/* CASE 35: SEARCH INSERT POSITION, SORTED ARRAY */

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        size_t size = nums.size();
        for (size_t i = 0; i < size; ++i) {
            if (target <= nums[i]) {
                return i;
            }
        }
        return size;
    }
};
