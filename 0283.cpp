/* CASE 283: MOVE ZEROES */

#include <utility> // std::swap elements in vector
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        // move all zeroes to the end of nums
        // all non-zeroes must be in the same order
        
        size_t first_zero = 0; // index of first zero element
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) { // found a non-zero element
                std::swap(nums[i], nums[first_zero]); 
                // the above line swaps the first zero with a non-zero,
                ++first_zero; // effectively shifts first zero element
            }
        }
    }
};
