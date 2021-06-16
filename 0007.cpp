/* CASE 7: REVERSE INTEGER DIGITS */

#include <utility> // swap()
#include <string> // to_string(), .front(), .substr(), npos, stoi()

class Solution {
    /* Some principles I abided by for this solution:
     * 1) don't use 64-bit data types (therefore no long, long long, uint64_t)
     * 2) don't return 64-bit data types */
    
    public:
        const std::string neg_limit = "2147483648";
        const std::string pos_limit = "2147483647";
    
        int reverse(int x) {
            std::string x_str = std::to_string(x);
            if (x_str.front() == '-') { // omit the sign for now
                x_str = x_str.substr(1,std::string::npos);
            }

            uint8_t length = x_str.length(); // assumption: encoding is 256 characters at longest
            for (uint8_t i = 0; i < (length / 2); ++i) {
                std::swap(x_str[i], x_str[length - 1 - i]);
            }
 
            if (((x < 0) && x_larger(x_str, neg_limit)) || 
                ((x > 0) && x_larger(x_str, pos_limit))) {
                return 0; // return 0 for numbers that are out of bounds
            }
            else {
                int rint = std::stoi(x_str);
                if (x < 0) {
                    rint *= -1;
                }
                return rint;
            }

        }
        
        /* returns larger (of two string encodings) of integers (not lexicographical) */
        bool x_larger(const std::string& x_str, const std::string& limit) {
            if (x_str.length() < limit.length()) {
                return false;
            }
            else if (x_str.length() == limit.length()) {
                return x_str > limit;
            }
            else {
                return true;
            }
        }
};
