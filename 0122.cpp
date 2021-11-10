/* CASE 122: SINGLE-STOCK MAXIMUM CUMULATIVE PROFIT */
// O(n) Time, O(1) Space

#include <vector>

// STOCKS II: ONE-STOCK, MANY-TIME PURCHASE, MANY-TIME SALE, MAXIMISE PROFIT

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profits = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i + 1] > prices[i]) {
                profits += prices[i + 1] - prices[i];
            }
        }
        return profits;
    }
};

/* CRUX of this problem: Eventual Profit == Maximum Profit
The solution can be simplified to just finding if the next element
is larger than the former, and summing all rises in the data.

This is because:
- we can buy and sell on the same day (in other words the minimum profit is 0, no less)
- we have the choice to consecutively sell it
*/

/* CONSIDER THE FOLLOWING EXAMPLES
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

What was done above, is to take the difference from the next day and add.

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

What was done above, is to remember the largest peaks, but
we also got back the same profit from adding all the gradual profits.


Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

What was done above, is to never add profit if the price next day was lower
*/
