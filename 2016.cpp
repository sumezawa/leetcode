/* CASE 2016: NON-SUCCESIVE MAX INCREASE IN ARRAY */

#include <vector>


// ASSUMPTIONS:
// n == nums.length, 2 <= n <= 1000
// 1 <= nums[i] <= 10^9
// search for the largest increase that is 
// not between successive elements, 
// but still a chronological increase

class Solution {
public:
    int maximumDifference(std::vector<int>& nums) {
        auto ptr = nums.begin();
        auto min_index = nums.begin();
        int max_diff = 0;
        
        while (ptr != nums.end()) {
            if (*ptr - *min_index > max_diff) {
                max_diff = *ptr - *min_index;
            }
            // MOST IMPORTANT PART OF THIS ALGORITHM:
            // again, this second for loop may
            // modify the min_index, but it
            // takes the first condition above
            // to potentially change max_diff
            if (*ptr < *min_index) {
                min_index = ptr;
            }
            ++ptr;   
        }
        
        if (max_diff == 0) {
            return -1;
        }
        else {
            return max_diff;
        }
    }
};
