/* CASE 27: REMOVE ALL INSTANCES IN AN ARRAY */

#include <vector>


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t k = 0; // # of elements when val is removed
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) { // ensures the target value is never stored in the first k elements
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};
