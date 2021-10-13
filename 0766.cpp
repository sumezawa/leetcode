/* CASE 766: TOEPLITZ MATRIX */

#include <vector>

// O(n) Time, O(1) Space
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        // compare the top left element (if it exists)
        size_t rmax = matrix.size();
        size_t cmax = matrix[0].size();
        for (size_t r = 0; r < rmax; ++r) {
            for (size_t c = 0; c < cmax; ++c) {
                if (r > 0 && c > 0 && (matrix[r][c] != matrix[r - 1][c - 1])) {
                    return false;    
                }
            }
        }
        return true; // every element is valid, matrix is Toeplitz
        
    }
};
