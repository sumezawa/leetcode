/* CASE 1576: REPLACE CHARACTERS AND AVOID REPEATING CHARACTERS */

#include <string>

class Solution {
public:
    std::string modifyString(std::string s) {
        for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
            if (*it == '?') {
                // we don't need all characters of the alphabet, just 3 unique letters
                // this is by a contrapositive of the pigeonhole principle:
                // if we have two pigeons, there will be space for each bird 
                // if there are three holes.
                for (*it = 'a'; *it < 'd'; ++(*it)) {
                    // three cases:
                    
                    // beginning, there's no left char
                    if (it == s.begin()) {
                        if (it == s.end() - 1) {
                            break; // one-character long string case; finished
                        }
                        else {
                            if (*it != *(it + 1)) {
                                break; // not at the end of string but character on the right is different; finished
                            }
                        }
                    }
                    
                    // end, there's no right char
                    else if (it == s.end() - 1) {
                        if (*it != *(it - 1)) {
                                break; // not at the end of string but character on the left is different; finished
                        }                        
                    }
                    
                    // need to check left and right chars
                    else {
                        if ((*(it) != *(it - 1)) && (*(it) != *(it + 1))) {
                            break;    
                        }
                    }
                }
            }
        }
        return s;
    }
};

/*
Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.

It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.

Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.

Example 1:

Input: s = "?zs"
Output: "azs"
Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".

Example 2:

Input: s = "ubv?w"
Output: "ubvaw"
Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".

Constraints:

    1 <= s.length <= 100
    s consist of lowercase English letters and '?'.

*/
