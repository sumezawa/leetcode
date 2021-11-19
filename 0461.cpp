/* CASE 461: HAMMING DISTANCE */

// Hamming distance - number of positions at which the corresponding bits are different for two numbers.

#include <string>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor_xy = x ^ y; // all of the different bits
        int ham = 0;
        while(xor_xy) {
            ++ham;
            xor_xy &= xor_xy - 1; // Brian Kernighan's method of decrementing xor terms.
        }
        return ham;
    }
};
