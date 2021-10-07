/* CASE 392: SUBSEQUENCE EXISTENCE */

#include <queue>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        
        // this algorithm lines up characters we want to see
        // (without disturbing order) and checks if a subsequence
        // exists in the larger string
        
        std::queue<char> charqueue;
        for (char c : s) {
            charqueue.push(c);
        }
        for (char c : t) {
            if (charqueue.front() == c) {
                charqueue.pop();
            }
        }
        return charqueue.empty();
    }
};
