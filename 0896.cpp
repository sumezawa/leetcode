/* CASE 896: MONOTONIC ARRAYS */
// check for either monotonic increase or monotonic decrease

#include <vector>

// 152ms on LeetCode; 72.67 percentile
// 96.5MB on LeetCode; 62.41 percentile

class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        
        // special case
        if (nums.size() == 1) {
            return true;
        }
        
        // standard case
        
        // choose increase or decrease
        bool increase = (nums.front() <= nums.back());
        std::vector<int>::iterator it = nums.begin();
        
        // monotonic increase check
        if (increase) {
            int max = *it; // maximum allowed value
            while (it != nums.end()) {
                if (*it < max) {
                    return false;
                }
                else {
                    max = *it;
                }
                ++it;
            } 
        }

        // monotonic decrease check
        else {
            int min = *it; // minimum allowed value    
            while (it != nums.end()) {
                if (*it > min) {
                    return false;
                }
                else {
                    min = *it;
                }
                ++it;
            }            
        }
        
        return true;
    }
};

/* 
Constraints:
1 <= nums.length <= 105
-105 <= nums[i] <= 105
*/
