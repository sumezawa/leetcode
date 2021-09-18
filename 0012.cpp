/* CASE 12: INTEGER TO ROMAN NUMERALS */

#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        int digit;
        int exponent = 0;
        std::string ans;
        while (num != 0) {
            digit = num % 10;
            if (exponent == 0) {
                if (digit < 4) {
                    for (int i = 0; i < digit; ++i) {
                        ans += "I";
                    }
                }
                else if (digit == 4) {
                    ans = "IV";
                }
                else if (digit > 4 && digit < 9) {
                    ans = "V";
                    for (int i = digit; i > 5; --i) {
                        ans += "I";
                    }
                }
                else {
                    ans = "IX";
                }
                ++exponent;
            }
            else if (exponent == 1) {
                std::string t;
                if (digit < 4) {
                    for (int i = 0; i < digit; ++i) {
                        t += "X";
                    }
                }
                else if (digit == 4) {
                    t = "XL";
                }
                else if (digit > 4 && digit < 9) {
                    t = "L";
                    for (int i = digit; i > 5; --i) {
                        t += "X";
                    }
                }
                else {
                    t = "XC";
                }
                ans = t + ans;
                ++exponent;
            }
            else if (exponent == 2) {
                std::string h;
                if (digit < 4) {
                    for (int i = 0; i < digit; ++i) {
                        h += "C";
                    }
                }
                else if (digit == 4) {
                    h = "CD";
                }
                else if (digit > 4 && digit < 9) {
                    h = "D";
                    for (int i = digit; i > 5; --i) {
                        h += "C";
                    }
                }
                else {
                    h = "CM";
                }
                ans = h + ans;
                ++exponent;
            }
            else {
                for (int i = 0; i < digit; ++i) {
                    ans = "M" + ans;
                }
            }
            num = num / 10;
        }
        return ans;
    }
};
