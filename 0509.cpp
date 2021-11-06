/* CASE 509: FIBONACCI NUMBERS */

// a toy example for Dynamic Programming

class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n; // F(0) = 0, F(1) = 1
        }
        else {
            int ans = 0;
            int f0 = 0;
            int f1 = 1;
            while (true) {
                ans = f0 + f1; // not +=, since F(n) = F(n - 1) + F(n - 2)
                --n;
                if (n < 2) {
                    break;
                }
                f0 = f1;
                f1 = ans;
            }
            return ans; 
        }
    }
};
