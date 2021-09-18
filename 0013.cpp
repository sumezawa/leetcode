/* CASE 13: ROMAN NUMERALS TO INTEGERS */


#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {

        std::unordered_map<char, int> rtoi;
        rtoi['I'] = 1;
        rtoi['V'] = 5;
        rtoi['X'] = 10;
        rtoi['L'] = 50;
        rtoi['C'] = 100;
        rtoi['D'] = 500;
        rtoi['M'] = 1000;
        
        int ans = 0;
        for (auto i = s.begin(); i != s.end(); ++i) {
            // STANDARD CASE
            if (rtoi[*i] >= rtoi[*(i + 1)]) {
                ans += rtoi[*i];
            }
            // SUBTRACTIVE CASE
            else {
                ans += (rtoi[*(i + 1)] - rtoi[*i]);
                ++i;
            }
        }
        
        return ans;
    }
};
