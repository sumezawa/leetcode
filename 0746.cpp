/* CASE 746: MIN COST CLIMBING STAIRS */

#include <cmath> // std::min()
#include <cstdlib> // std::size_t
#include <vector>
// O(n) time, O(1) space

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int two_steps_prior = cost[0];
        int one_step_prior = cost[1];
        int current_step;
        for (std::size_t i = 2; i < cost.size(); ++i) {
            current_step = cost[i] + std::min(two_steps_prior, one_step_prior);
            // shift entries
            two_steps_prior = one_step_prior;
            one_step_prior = current_step;
        }
        
        // algorithm calculates optimal cost starting from one or two steps
        // before the end; we just take the cheaper one for the final step.
        return std::min(two_steps_prior, one_step_prior);
    }
    
    int on_space_minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> optimal(cost.size(), 0);
        
        // LeetCode guarantees that cost array is 2 or more elements long.
        optimal[0] = cost[0];
        optimal[1] = cost[1];
        
        for (std::size_t i = 2; i < cost.size(); ++i) {
            optimal[i] = cost[i] + std::min(optimal[i - 1], optimal[i - 2]);       
        }
        
        // algorithm calculates optimal cost starting from one or two steps
        // before the end; we just take the cheaper one for the final step.
        return std::min(optimal[cost.size() - 1], optimal[cost.size() - 2]);
    }
};

/* TIPS
1. if empty array, no cost, finish
2. if singleton array, pay the cost, finish
3. if 
4. the above two are base cases to the recurrence relation in 5.
   however, 1., 2., are impossible as 
   LeetCode testcases only have arrays of size 2 or larger.
5. if you're at some step i < n, where n is the total input size,
   the optimal cost for reaching that step i and landing there is:
   optimal_cost[i] = cost[i] + min(cost[i - 1], cost[i - 2])
*/

   
/* PROBLEM DESCRIPTION

You are given an integer array cost where 
cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Constraints:

    2 <= cost.length <= 1000
    0 <= cost[i] <= 999

*/
