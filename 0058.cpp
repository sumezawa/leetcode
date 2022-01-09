/* CASE 58: LAST WORD LENGTH */

#include <string>

class Solution {
public:
    
    // fast, we only traverse the last word of the string and terminate
    // 0ms, 100 percentile of all LeetCode submissions
    int lengthOfLastWord(std::string s) {
        // standard case
        int length = 0;
        int tail = s.size() - 1;
        while (tail >= 0 && s[tail] == ' ') {
            --tail;
        }
        while (tail >= 0 && s[tail] != ' ') {
            --tail;
            ++length;
        }
        return length;
    }    
    
    // slow, we need last word, we DONT need to go through entire string.
    // 9 ms, 7.17 percentile of all LeetCode submissions
    int slow_lengthOfLastWord(std::string s) {
        int length = 0;
        bool end_word = true;
        for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
            if (end_word && *it != ' ') {
                end_word = false;
                length = 1; // reset the count
            }
            else if (end_word && *it == ' ') {
                end_word = true;    
            }
            
            else if (!end_word && *it != ' ') {
                ++length;   
            }
            
            else if (!end_word && *it == ' ') {
                end_word = true;    
            }
        }
        return length;
    }
};

/* 

Given a string s consisting of some words separated by some number of spaces, 
return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

*/
