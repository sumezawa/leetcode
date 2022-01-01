/* CASE 70 CLIMBING STAIRS */
// O(n) time, O(1) space


class Solution {
public:
    int climbStairs(int n) {
        if (n < 4) {
            return n; // climbStairs(1) = 1, climbStairs(2) = 2, climbStairs(3) = 3
        }
        else {
            unsigned int ans = 0;
            unsigned int f1 = 1; // we start with Fibonacci sequence F(1) = 1, F(2) = 1
            unsigned int f2 = 1;
            while (true) {
                ans = f1 + f2; // not +=, since F(n) = F(n - 1) + F(n - 2)
                --n;
                if (n < 2) {
                    break;
                }
                f1 = f2;
                f2 = ans;
            }
            return ans; 
        }
    }
};

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*
Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

1 <= n <= 45
*/

/*
TIPS:
1) there is only 1 way to complete a 1-step staircase
2) there is only 1 way to go from the first to second step.
3) there are only 2 ways to go from the first to the third step, (2 difference)
   either first to third in one 2-step, or first to second, second to third in two 1-steps.
4) there are only 3 ways to from the first to fourth step (3 difference);
   there is one way to go from first to second, and three ways to go from second to fourth (2 difference)
5) this is the Fibonacci sequence, which can be computed in O(n) time, O(1) space.
*/
