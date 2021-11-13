/* CASE 123: TWO-TIME TRANSACTION MAXIMISE PROFITS */
// O(n) Time, O(1) Space

// STOCKS III: ONE-STOCK, 2 TRANSACTIONS, MAXIMISE PROFIT
// this code depends on a recurrence relation that have t (< unlimited) transactions

#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int p_2s = 0;           // max profit, second stock sold
        int p_2p = -2147483648; // max profit, second stock purchased
        int p_1s = 0;           // max profit, first stock sold 
        int p_1p = -2147483648; // max profit, first stock purchased
        
        for (std::vector<int>::iterator price = prices.begin(); price != prices.end(); ++price) {
            p_2s = maximum(p_2s, p_2p + *price);
            p_2p = maximum(p_2p, p_1s - *price);
            p_1s = maximum(p_1s, p_1p + *price);
            p_1p = maximum(p_1p, 0 - *price);
            
            // notice: we don't have indices to indicate today's or yesterday's cost.
            // HOWEVER
            // we do use the 'old' values of p_2p, p_1s, p_1p to yield the best p_2s so far.
        }
        
        return p_2s;
    }
    
    // helper function
    int maximum(int a, int b) {
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
};

/* Some tips to understand this code:
    - first, notice that this is a dynamic programming problem:
      We need not only know whether we have yet to purchase or 
      sell a stock, the maximum profit with the sale, but all
      previous transactions and all of the profits from before.
      
      however, we need not re-calculate all previous transactions.
      The following explanation will reveal that yesterday's profits
      completely encode all previous transactions, so memory usage is
      O(1).
      
    - second, notice that we can create a recurrence relation 
      for the n-th day, for t = 1 transaction (one transaction)
      and generalise to n-th day for t = 2+ transactions with
      the following:
      
      letting P[t,s,n] = t transactions left, s stocks held, n-th day
          where 
          - t_begin >= t >= 0, # of transactions you begin with
          - 0 <= s <= 1, # of stocks held
          - 0 <= n <= n_final - 1, # of days stock exchange open. 0 is the first day.
      we can have a function of profit P, for example
          - P[1, 0, 0] = profit @ one transaction left, no stock held, first day of transaction
          - P[1, 1, 6] = profit @ one transaction left, one stock held, sixth day of transaction
      and we can relate different P with recurrence relations based on
      three variables, t # of transactions, s # of stocks held, and n the days elapsed.
      
      To characterise today's maximum profit with respect to yesterday, we get:
          - P[t,0,n] = max(P[t,0,n - 1], P[t,1,n - 1] + prices[n])
      which models the fact that today's profit, given t transactions remaining, no stocks in hand,
      is either yesterday's profits with t transactions remaining, no stocks in hand (do nothing) or
      yesterday's profits with t transactions remaining, one stock in hand plus today's price (sale).
          - P[t,1,n] = max(P[t,1,n-1], P[t - 1,0,n-1] - prices[n])
      which models the fact that today's profit, given t transactions remaining, one stock in hand,
      is either yesterday's profit with t transactions remaining, one stock in hand (do nothing) or
      yesterday's profits with t - 1 transactions remaining, no stock in hand plus today's price (purchase). 
    
      The actions in parentheses are exactly the actions possible on any given day (except edge cases),
      as specified by the problem statements in Stocks I, Stocks II, (This problem Stocks III), and more.
      
    - third, for the above relations, consider the edge (or rather base cases) of the relation:
         - For all days before the starting day (n = 0), there is no transaction, so 
           there is no profit nor loss. Therefore P[k,0,-1] = 0.
           
         - For any day before the starting day (n = 0), it is impossible for someone to hold a stock.
           For the sake of a functioning code, we let P[k,1,-1] = Negative Infinity.
           
         - For any day after using up your last transaction (t = 0), it is impossible to purchase stock again.
           For the sake of a functioning code, we let P[0,1,n >= 0] = Negative Infinity.
           
         - For any day after using up your last transaction (t = 0), there is no transaction nor sale, so 
           there is no profit nor loss. Therefore P[0,0,n >= 0] = 0.
    
    JUSTIFICATION FOR CORRECTNESS OF THE RECURRENCE RELATIONS:
    
    - fourth, if only one transaction is allowed:
      - P[1,0,n] = max(P[1,0,n-1], P[1,1,n - 1] + prices[n]) yesterday no change vs. yesterday + today's price
      - P[1,1,n] = max(P[1,1,n-1], P[0, 0, n - 1] - prices[n]) yesterday no change vs. - today's price
      Notice, P[0,0,n-1] is a base case, 0, for any n, so really the relation is:
      - P[1,0,n] = max(P[1,0,n-1], P[1,1,n - 1] + prices[n])
      - P[1,1,n] = max(P[1,1,n-1], 0 - prices[n])
      If n = 0, then
      - P[1,0,0] = max(P[1,0,-1], P[1,1,-1] + prices[0]) = max(0, -infinity + prices[0]) = 0
      - P[1,1,0] = max(P[1,1,-1], 0 - prices[0]) = max(-infinity, - prices[0]) = -prices[0]
      for n = 1,
      - P[1,0,1] = max(P[1,0,0], P[1,1,0] + prices[0]) = max(0, -prices[0] + prices[1])
      - P[1,1,1] = max(P[1,1,0], 0 - prices[1]) = max(-prices[0], -prices[1])
      
      Although this is a hand-wavy explanation, it is now (a little bit more) obvious that
      the upper relation takes the minimum price from the lower relation and evaluates 
      whether the profit yielded is greater than the profit of not doing anything.
      
      Suppose price[0] < price[1] (-price[0] > -price[1]).
      - P[1,0,1] = prices[1] - prices[0], P[1,1,1] = -prices[0]. 
      
    - fifth, although we can't actually do any more transactions, we can retroactively nullify previous
      transactions for a higher-profit transaction later on. This 'replacement' of transactions
      will reverberate for higher order examples (more than one transaction allowed):
      - P[2,0,n] = max(P[2,0,n-1], P[2,1,n-1] + prices[n])
      - P[2,1,n] = max(P[2,1,n-1], P[1,0,n-1] - prices[n])
      - P[1,0,n] = max(P[1,0,n-1], P[1,1,n-1] + prices[n])
      - P[1,1,n] = max(P[1,1,n-1], 0 - prices[n])
      
      Notice for the second relation, max profit partially depends on one stock purchased when
      there is no stock in hand minus today's price. This maximum goes up only when the lower
      relations P[1,1,n], P[1,0,n] increase in value. Over time, the maximum peaks encountered
      are absorbed by the lower relations, and the upper relations with more stocks sold will
      remember the most profitable transactions when calculating its own maximum profit.
*/      
