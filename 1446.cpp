/* CASE 1446: CONSECUTIVE CHARACTERS RANK */

#include <string>

// The power of the string is the maximum length of a non-empty substring 
// that contains only one unique character.
class Solution {
    public:
        int maxPower(std::string s) {
            char max_cchar = s.front(); // get first char
            int current_max = 1;
            int temp = 1;
            for (std::string::iterator it = s.begin() + 1; it != s.end(); ++it) { // begin from second char
                if (*it == max_cchar) {
                    ++temp;
                    if (temp > current_max) {
                        current_max = temp;
                    }
                }
                else {
                    max_cchar = *it;
                    temp = 1;
                }
            }
            return current_max;
        }
};
