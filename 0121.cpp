/* CASE 121: MINIMUM PURCHASE MAXIMUM SALE */
// O(n) Time, O(1) Space
// Inspired by Kadane's Algorithm for Maximum Subarray

#include <stdint.h>
#include <vector>

// STOCKS I: ONE-STOCK, ONE-TIME PURCHASE, ONE-TIME SALE, MAXIMISE PROFIT

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // SPECIAL CASE
        if (prices.size() < 2) {
            return 0;
        }
        
        // STANDARD CASE
        uint16_t min_price = prices[0];
        uint16_t max_profit = 0;
        for (int price : prices) {
            // all we need is
            // 1) minimum price
            if (price < min_price) {
                min_price = price;
            }
            // 2) best profit based on
            // the minimum price so far
            else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }
        return max_profit;  
    }
};
