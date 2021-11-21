/* CASE 231: POWER OF TWO */

// if the integer is a power of 2,
// in binary, it is 0, 10, 100, 1000.
// there is only 1 '1' bit, and we can check for uniqueness
// by bitwise ANDing the number with the number - 1.
// if all the digits of the result is 0, then the number is a power of 2

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false; // negative numbers are not powers of 2
        }
        return ((n & (n - 1)) == 0);
    }
};
