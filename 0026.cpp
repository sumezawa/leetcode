/* CASE 26: REMOVE DUPLICATES, SORTED ARRAY */

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // modify the array itself for pass-by-reference
        // SPECIAL CASE (empty array)
        if (nums.size() < 1) {
            return 0;
        }
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
