/* CASE 1480: RUNNING SUM */

#include <vector>


class Solution {
public:
    // RUNNING SUM VECTOR -> 
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> rsum; // std::vectors are arrays that are initialised to 0
        std::vector<int>::iterator rsit = rsum.begin(); // auto works too
        
        // demonstrated below,
        // vectors can be accessed with the [] operator or by dereferencing iterators
        *rsit = nums[0];
        
        // demonstrated below,
        // std::vector arrays 1) need not track array size 2) can add as many elements as we want
        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            *rsit += *(it - 1);
        }
        return rsum;
    }
};
