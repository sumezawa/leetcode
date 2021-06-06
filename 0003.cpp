/* CASE 3.5: LONGEST SUBSTRING WITH UNIQUE CHARACTERS */
/* in Leetcode, the code below will run into a runtime error
 * My code is also different from what Leetcode asks for,
 * which is for the length of the longest substring with
 * unique characters. 
 
 * behaviourally, the code that passes their tests do not
 * return the correct substring, for example,
 * my code on Leetcode will return "w" for a string "pww"
 * my code here will return "pw" for a string "pww"

 * hence the code below is not accepted by Leetcode;
 * nevertheless, the code below leaves no memory leaks
 * and it can return substrings given input char size
 * no greater than 65536
 */


#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    const uint16_t& get_max(const uint16_t& n1, const uint16_t& n2) {
        if (n1 >= n2) {
            return n1;
        }
        else {
            return n2;
        }
    }

    int length_longest_substring(std::string s) {
        // SPECIAL CASES
        if ((s.size() == 0) || (s.size() == 1)) {
            return s.size();
        }

        // NORMAL CASES
        return longest_substring(s).size();
    }

    std::string longest_substring(std::string s) {
        uint16_t window_begin = 0; // internal substring start index
        uint16_t window_length = 0; // internal window length

        uint16_t substring_begin = 0; // return value substring start index
        uint16_t substring_length = 0; // return value substring length

        std::string temp;

        std::unordered_map<char, uint16_t> htable; // key = character, value = location in string (index in string)

        // if we find the starting index and length of the longest substring, we can obtain that substring
        // a given constraint is string length is up to 5 * 10^4, which is larger than what int supports
        for (uint16_t window_end = 0; window_end < s.size(); ++window_end) {
            if (htable.find(s[window_end]) != htable.end()) { // if character is not unique
                window_begin = get_max(window_begin, htable[s[window_end]] + 1); // move window to new starting position
            }
            else { // character is unique
                // do not move window, ending character is unique
                window_length = get_max(window_length, window_end - window_begin + 1); // expand window
                if (window_length > substring_length) { // if the substring covered by the new window is larger than current largest substring
                    substring_begin = window_begin; // new largest substring is the substring covered by the window
                    substring_length = window_length;

                    temp = s.substr(substring_begin, substring_length);
                    for (std::unordered_map<char, uint16_t>::iterator it = htable.begin(); it != htable.end(); ++it) {
                        if (temp.find(it->first) == std::string::npos) {
                            htable.erase(it->first); // eliminate hash entries that are not characters of the new substring
                        }
                    }
                }
            }
            // update latest instance of the character traversed
            htable[s[window_end]] = window_end;
        }

        return s.substr(substring_begin, substring_length);
    }
};

int main() {
    Solution s;
    std::string a("abcabcbb"); // yields abc

    std::cout << s.length_longest_substring(a) << std::endl;
    std::cout << s.longest_substring(a) << std::endl;

    a = "pw"; // yields pw (Leetcode wants 'w')
    std::cout << s.length_longest_substring(a) << std::endl;
    std::cout << s.longest_substring(a) << std::endl;

    a = "pwwkew"; // yields wke
    std::cout << s.length_longest_substring(a) << std::endl;
    std::cout << s.longest_substring(a) << std::endl;

    a = "bbbbb"; // yields b
    std::cout << s.length_longest_substring(a) << std::endl;
    std::cout << s.longest_substring(a) << std::endl;

    a = "tmmzuxt"; // yields mzuxt
    std::cout << s.length_longest_substring(a) << std::endl;
    std::cout << s.longest_substring(a) << std::endl;

    a = "testcode"; // yields estcod
    std::cout << s.length_longest_substring(a) << std::endl;
    std::cout << s.longest_substring(a) << std::endl;

    return 0;
}
