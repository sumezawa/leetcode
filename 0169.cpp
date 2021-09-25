/* CASE 169: MAJORITY ELEMENT IN ARRAY */
// O(n) Time, O(1) Space

#include <stdint.h>
#include <vector>
// checking every element or 'vote' is O(n)

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int max = nums[0];
        int count = 0;
        
        // O(1) is possible because majority element
        // will appear more than half the time
        // we will get a candidate that dominates in counts
        for (uint16_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == max) {
                ++count;
            }
            else {
                if (count == -1) { // using 0 breaks
                    max = nums[i];
                    ++count;
                }
                else {
                    --count;
                }
            }
        }
        
        return max;
    }
};
