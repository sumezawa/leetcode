/* CASE 326: POWER OF THREE */

class Solution {
public:
    bool isPowerOfThree(int n) {
        // if i could, i would have checked
        // the first and last bits (since
        // powers of three begin and end with 1)

        // HOWEVER! (^_^ MATH 8 TIME)
        // All powers of three divide
        // the largest power of three
        // expressable in 32-bit signed int:
        // for all n < 20: 3^19 mod 3^n = 0!
        return (n > 0 && 1162261467 % n == 0);
    }
};
