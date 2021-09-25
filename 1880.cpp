/* CASE 1880: SUM OF DECIMAL NUMBERS ENCODED IN CHARS */

#include <stdint.h>
#include <string>


class Solution {
public:
    bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
        uint32_t sum1 = 0;
        // because the letters are only a to j inclusive, we can use ASCII
        // because the inputs do not exceed length of 8, the indices need not use 4 bytes like int does
        // with length of 8, the maximum sum possible is 99999999 * 2, which exceeds uint16_t but not uint32_t

        // finally:
        // 4 = 0 * 10 + 4
        // 42 = (4 * 10) + 2
        // 420 = (42 * 10) + 0
        // 4206 = (420 * 10) + 6
        // 42069 = (4206 * 10) + 9
        // i.e. every for loop iteration need only add the LSB to 10 times the previous iteration
        for (uint8_t index = 0; index < firstWord.size(); ++index) {
            sum1 *= 10;
            sum1 += firstWord[index] - 'a';
        }

        uint32_t sum2 = 0;
        for (uint8_t index = 0; index < secondWord.size(); ++index) {
            sum2 *= 10;
            sum2 += secondWord[index] - 'a';
        }

        uint32_t sum3 = 0;
        for (uint8_t index = 0; index < targetWord.size(); ++index) {
            sum3 *= 10;
            sum3 += targetWord[index] - 'a';
        }

        return (sum1 + sum2) == sum3;
    }
};
