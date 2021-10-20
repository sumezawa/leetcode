/* CASE 409: LONGEST PALINDROME */

#include <string>
#include <unordered_map>
// on LeetCode, using uint16_t uses up more memory :( bruh

class Solution {
public:
    int longestPalindrome(std::string s) {
        // SPECIAL CASES
        if (s.size() == 1) {
            return 1;
        }
        if (s.size() == 2 && s[0] == s[1]) {
            return 2;
        }
        
        // STANDARD CASE
        // a palindrome is made of:
        // - all of the letters with count 2k, k is some natural number
        // - all of the letters with count 2k + 1, k is some natural number, but adding only 2k each
        // - if it is the largest odd, you add that odd as well
        // - but dont add the largest odd until you know its the largest odd
        
        // SMARTER IMPLEMENTATION (cuts down a lot of if statements)
        // notice that (and prove it later)
        // - if the palindrome size is less than that of the string size, you always add 1
        
        std::unordered_map<char, int> htable;
        for (auto it = s.begin(); it != s.end(); ++it) {
            ++htable[*it]; // hash tables are defaulted to 0. WOW!
        }
        
        int max_palin = 0;
        for (auto entry : htable) {
            if (entry.second % 2 == 0) {
                max_palin += entry.second;
            }
            else {
                max_palin += entry.second - 1;
            }
        }
        if (max_palin < s.size()) {
            return max_palin + 1;
        }
        else {
            return max_palin;
        }
    }
};
