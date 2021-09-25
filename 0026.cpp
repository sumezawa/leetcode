/* CASE 26: REMOVE DUPLICATES, SORTED ARRAY */

#include <vector>


class Solution {
public:
    // this function modifies the array itself (pass-by-reference)
    // this function returns the size of the new array
    int removeDuplicates(std::vector<int>& nums) {
        // SPECIAL CASE (empty array)
        if (nums.size() < 1) {
            return 0;
        }
        // STANDARD CASE
        else { 
            size_t pointer = 1;
            for (size_t i = 1; i < nums.size(); ++i) {
                if (nums[pointer - 1] < nums[i]) {
                    nums[pointer] = nums[i];
                    pointer++;
                }
            }
            return pointer;
        }
    }
};
