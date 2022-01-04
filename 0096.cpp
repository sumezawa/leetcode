/* CASE 96: UNIQUE BINARY SEARCH TREES */

/*
Given an integer n, 
return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n.

*/

#include <vector>


class Solution {
public:
    int numTrees(int n) {
        // DP to store the number of unique BST with key i
        std::vector<int> dp(n + 1, 0);

        // Base case
        dp[0] = 1;
        dp[1] = 1;

        // fill the dp table in top-down approach.
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {

                // n-i in right * i-1 in left
                dp[i] = dp[i] + (dp[i - j] * dp[j - 1]);
                // dp[2] = dp[2] + (dp[1] * dp[0]);
                // dp[2] = 0 + 1;
                // dp[2];
                // dp[2] = dp[2] + (dp[0] * dp[1]);
                // dp[2] = 1 + 1;
                // dp[2] = 2;
                // dp[3] = dp[3] + (dp[2] * dp[0]);
                // dp[3] = 0 + 2;
                // dp[3] = 2;
                // dp[3] = dp[3] + (dp[1] * dp[1]);
                // dp[3] = 2 + 1;
                // dp[3] = 3;
                // dp[3] = dp[3] + (dp[0] * dp[2]);
                // dp[3] = 3 + 2;
                // dp[3] = 5;
            }
        }
        
        return dp[n];
    }
};

/* TIPS
1. A BST obeys the rule that the left subtrees are less than itself, right subtrees are greater than itself
2. This is a Dynamic Programming problem, such that we need to know what node values were used before.
3. Each node has a unique value.
*/
