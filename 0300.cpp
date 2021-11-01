/* CASE 300: LONGEST INCREASING SUBSEQUENCE */

#include <vector>

// An O(n^2) CS130B Dynamic Programming Implementation
// vector length is less than 2500
// element can be from -10000 to 10000
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        short size = nums.size();
        std::vector<short> subseqs; // holds all subseq lengths
        
        for (short i = 0; i < size; ++i) {
            subseqs.push_back(1);
            for (short j = 0; j < i; ++j) {
                if (subseqs[j] + 1 > subseqs[i] && nums[j] < nums[i]) {
                    subseqs[i] = subseqs[j] + 1;
                }
                // check if you can make a longer subseq
                // by going back to all previously encountered elements
                // this is why this algorithm is O(n^2)
            }
        }
        
        short max = 1;
        for (short i = 0; i < size; ++i) {
            if (subseqs[i] > max) {
                max = subseqs[i];
            }
        }
        
        return static_cast<int>(max);
        
    }
};
