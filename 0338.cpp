/* CASE 338: RECURSIVE DEFINITION FOR NUMBER OF 1'S IN A BIT */

#include <vector>


class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n + 1);
        
        // there's actually a pattern involved in counting the number of 1's in a binary representation
        // 0 1
        // 1 2
        
        // 0 1 1 2
        // 1 2 2 3
        
        // 0 1 1 2 1 2 2 3
        // 1 2 2 3 2 3 3 4
        
        // 0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4
        // 1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5
        
        // the first five values can be evaluated with previous values:
        // f(0) = 0
        // f(1) = f(0) + 1
        // f(2) = f(1) = f(0) + 1
        // f(3) = f(2) + 1 = f(1) + 1 = f(0) + 2 ... = f(3/2) + 1
        // f(4) = f(3) - 1 = f(2) = f(1) = f(0) + 1
        
        // the key observation is that the following recursive definition holds for all n
        // f(3) = f(3/2) + 3 mod 2 = f(1) + 1 = 1 + 1 = 2
        // f(4) = f(4/2) + 4 mod 2 = f(2) + 0 = 1 + 0 = 1
        
        ans[0] = 0;
        for (uint32_t i = 1; i < n + 1; ++i) {
            // we only need to lookup by index, so a vector suffices as a constant time lookup for this function
            ans[i] = ans[i/2] + (i % 2);
        }

        return ans;
    }
};
