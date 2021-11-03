/* CASE 1143: LONGEST COMMON SUBSEQUENCE */

#include <string>

// text length is less than 1000, and only contain lowercase letters
// DP algorithm that stores LCS length of the best subsequence up to
// that point in the for-loop iteration. O(n^2) Time, O(n^2) Space

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        short r = text1.size(); // rows
        short c = text2.size(); // columns
        short i, j;
        
        // the LCS length table must have an extra top row with 0's and left column with 0's.
        // this is because my implementation refers to the top, top-left, or left entry to
        // decide on the LCS - the first row and each column refer to 0's by default.
        short L[r + 1][c + 1]; 
       
        // insert current LCS length into table
        for (i = 0; i <= r; ++i) {
            for (j = 0; j <= c; ++j) { // for this algorithm index = 0 does not correspond to first char
                
                if (i == 0 || j == 0) {
                    L[i][j] = 0; // base cases 
                }

                else if (text1[i - 1] == text2[j - 1]) { // index = 1 corresponds to first char
                    L[i][j] = 1 + L[i - 1][j - 1];
                }
                
                else {
                    L[i][j] = maxlen(L[i - 1][j], L[i][j - 1]);
                }
            }
        }
        
        // we needed results from previous iterations
        // to return the correct final value, so
        // this is O(n^2) and Dynamic Programming
        
        return L[r][c];
    }
    
    short maxlen(short a, short b) {
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
};

// short demonstration
// rows: ABCD, columns: BBCD
// going from top-down, left-to-right
//     B B C D
//   0 0 0 0 0
// A 0 0 0 0 0
// B 0 1 1 1 1 // BB, BB are Top Left + 1, BC, BD are max(Left, Top)
// C 0 1 1 2 2
// D 0 1 1 2 3 // return 3

// short quip: max element arrives at the final row / final column, but not necessarily monotonically
