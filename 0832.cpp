/* CASE 832: MATRIX REFLECTION AND BIT MANIPULATION */

#include <cstdlib>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        std::size_t row_size = image[0].size();
        
        // horizontal flip
        for (std::vector<std::vector<int>>::iterator rit = image.begin(); rit != image.end(); ++rit) {
            for (std::size_t c = 0; c < (row_size + 1) / 2; ++c) {
                std::swap((*rit)[c], (*rit)[row_size - 1 - c]); // swap columns (need to swap only halfway) 
            }
            for (std::vector<int>::iterator cit = rit->begin(); cit != rit->end(); ++cit) {
                *cit = *cit ^ 1; // swap bits == take bitwise XOR of 1 with the elements, store output in the matrix
            }
        }
        
        // invert bits
        
        
        return image;
    }
};

/* Constraints:
    n x n matrix
    n == image.length
    n == image[i].length
    1 <= n <= 20
    images[i][j] is either 0 or 1.
*/
