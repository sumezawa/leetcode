
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
          - P[t,0,n] = max(P[t,0,n - 1], P[t,1,n - 1] + prices[i])
      which models the fact that today's profit, given t transactions remaining, no stocks in hand,
      is either yesterday's profits with t transactions remaining, no stocks in hand (do nothing) or
      yesterday's profits with t transactions remaining, one stock in hand plus today's price (sale).
          - P[t,1,n] = max(P[t,1,n-1], P[t - 1,0,n-1] - prices[i])
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

    - fourth, recurrence relations based on yesterday's profits must be 

*/      
