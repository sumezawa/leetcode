/* CASE 9: PALINDROME INTEGERS */

#include <string>
#include <utility> // swap()

class Solution {
public:
    bool isPalindrome(int x) {
        // SPECIAL CASES
        if (x < 0) {
            return false;
        }
        
        else if (x == 0) {
            return true;
        }
        
        // NORMAL CASES
        else {
            std::string num = std::to_string(x);
            std::string flip(num);
            size_t length = flip.length();
            for (uint8_t i = 0; i < (length / 2); ++i) {
                std::swap(flip[i], flip[length - 1 - i]);
            }
            return num == flip;
        }
    }
};
