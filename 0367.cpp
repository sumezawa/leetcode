/* CASE 367 PERFECT SQUARES */

class Solution {
public:
    bool isPerfectSquare(int num) {
        // Hearken back to MATH 8:
        // all perfect squares are successive sums of odd natural numbers
        // 1
        // 4 = 1 + 3
        // 9 = 1 + 3 + 5
        
        // the largest perfect square in signed 32-bit is 46340^2:
        if (num > 2147395600) {
            return false; // 46341^2 and larger is not expressable
        }
        
        // STANDARD CASE (less than 46340^2)
        int odd = 1;
        int inc = 0;
        while (inc <= num) {
            if (inc == num) {
                return true;
            }
            
            inc += odd; // add the next odd number
            odd += 2; // prepare the next odd number
            
        }
        return false;
    }
};
