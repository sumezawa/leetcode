/* CASE 1329: MATRIX DIAGONAL SORT */

#include <algorithm> // omit if you implemented your own sort
#include <unordered_map> // omit if you implemented your own hash table
#include <vector> // omit if you implemented your own dynamic array

// Goal: given some m x n matrix, take each diagonal of the matrix, and sort those diagonals

class Solution {
    public:
        std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat) {
            int num_rows = mat.size();
            int num_columns = mat[0].size();
            
            // LeetCode Hint 1:
            // key = unique diagonal id, values = all elements in that diagonal 
            std::unordered_map<int, std::vector<int>> diagonals; 
            
            
            // LeetCode Hint 2 and 3:
            // Any element in the matrix will have some associated diagonal.
            // Cells in the same diagonal share the property that
            // the arithmetic difference between their row index and column index are all equal.
            //
            // e.g. consider the indices of a 4 x 4 matrix (row, column):
            // (0,0) (0,1) (0,2) (0,3)
            // (1,0) (1,1) (1,2) (1,3)
            // (2,0) (2,1) (2,2) (2,3)
            // (3,0) (3,1) (3,2) (3,3)
            // (0 - 0) = (1 - 1) = (2 - 2) = (3 - 3) = 0
            // (0 - 1) = (1 - 2) = (2 - 3) = -1
            // etc.
            
            for (int r = 0; r < num_rows; ++r) {
                for (int c = 0; c < num_columns; ++c) {
                    diagonals[r - c].push_back(mat[r][c]); // most important idiom for this question
                }
            }
            
            // Q: How many diagonals do we need to sort for an m x n matrix?
            // 4x4 -> 7, 0 - 0, 0 - 1, 0 - 2, 0 - 3, 1 - 0, 2 - 0, 3 - 0
            // 1x1 -> 1, 0 - 0
            // 1x2 -> 2, 0 - 0, 0 - 1
            // 2x1 -> 2, 0 - 0, 1 - 0
            // 2x2 -> 3, 0 - 0, 0 - 1, 1 - 0
            // A: Arithmetic sum of rows and columns - 1. However, this 
            //    question fails to consider that the hash table stores 
            //    DIFFERENCES of the row/column indices as keys 
            //    distinguishing the different diagonals.
            //
            // Q: How do we iterate over the diagonals? (LeetCode Hint 2)
            // A: start from the most negative index difference (0th row, n - 1 column) = 0 - (n - 1)
            //    and iterate up the most positive index difference (m - 1 row, 0th column) = m - 1 - 0
            
            for (int i = - (num_columns - 1); i <= num_rows - 1; ++i) {
                std::sort(diagonals[i].begin(), diagonals[i].end());
            }
            
            // Q: How do we return the correct matrix?
            // A: Just do the double for-loop in reverse (because there is no pop_front)
            
            std::vector<std::vector<int>> sorted_mat(num_rows, std::vector<int>(num_columns, 0));
            for (int r = num_rows - 1; r >= 0; --r) {
                for (int c = num_columns - 1; c >= 0; --c) {
                    sorted_mat[r][c] = diagonals[r - c].back();
                    diagonals[r - c].pop_back();
                }
            }
            
            return sorted_mat;
        }        
};
