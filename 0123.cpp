/* CASE 123: SINGLE-STOCK, TWO TRANSACTIONS, MAXIMUM PROFIT */
// O(n) Time, O(1) Space

#include <vector>

// STOCKS III: ONE-STOCK, TWO NON-OVERLAPPING TRANSACTIONS, MAXIMISE PROFIT

// generalisation of how the maximum profit you can attain overall
// is a function of the number of transactions and number of stocks that you have

// 1 TRANSACTION STATE MACHINE
// state transitions for 1 transaction at a time, 1 transaction only.
// if we are at max profit today, 0 stocks held, we transitioned from either:
//     - max profit yesterday, 0 stocks held (did nothing)
//     - max profit yesterday, 1 stocks held + today's stock price (sold this stock)
// VERY IMPORTANT: ADDITIONALLY, we lose our option to do a transaction
// 
// if we are at max profit today, 1 stock held, we transitioned from either:
//     - max profit yesterday, 0 stocks held - today's stock price (buy this stock)
//     - max profit yesterday, 1 stock held (did nothing) ... default option if no transaction left.

// at the end of the for loop, the profit we look for is the state machine
// that has 0 stocks held: having a stock held at the end is always worse than 0 held:
//     - if you couldn't make a profit up to now, you would have never bought it
//     - if you could make a profit up to now, you would have sold it

// we need to consider base cases: what is the max profit yesterday, but purchase / sale began today?
//     - max profit for day before first day, 0 stocks held is 0
//     - max profit for day before first day, 1 stocks held is impossible (we couldn't buy prior)



// 2+ TRANSACTIONS STATE MACHINE
// The best profit after the last transaction depends on 
// the result of each transaction that occured before

// that relation is as follows:
// you have n transactions left at the beginning, no stocks held, 0-th day.
// Let T[t, 0, n] = transaction[# transactions allowed, stocks held, n-th day]
// generally,
// T[t, 0, n] = max(T[t, 0, n - 1], T[t, 1, n - 1] + prices[n])
// T[t, 1, n] = max(T[t, 1, n - 1], T[t - 1, 0, n - 1] - prices[n])
// where the terminating / base cases are
// T[t, 1, -1] = impossible, you can't possess a stock before transactions begin
// T[0, 1, any day] = impossible, unable to sell if you cant do transactions
// T[t, 0, -1] = 0, no stocks to purchase nor sell, so no profit
// T[0, 0, any day] = 0, no transaction left and no stock held, so no profit today

// for the purposes 
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        unsigned short one_held1; // today's max profit for one stock held, first transaction
        unsigned short zero_held1; // today's max profit for no stocks held, first transaction
        unsigned short one_held2; // today's max profit for one stock held, second transaction
        unsigned short zero_held2; // today's max profit for no stocks held, second transaction
        
    }
};

Similar to the case where k = 1, except now we have four variables instead of two on each day: T[i][1][0], T[i][1][1], T[i][2][0], T[i][2][1], and the recurrence relations are:

T[i][2][0] = max(T[i-1][2][0], T[i-1][2][1] + prices[i])
T[i][2][1] = max(T[i-1][2][1], T[i-1][1][0] - prices[i])
T[i][1][0] = max(T[i-1][1][0], T[i-1][1][1] + prices[i])
T[i][1][1] = max(T[i-1][1][1], -prices[i])
