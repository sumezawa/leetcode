/* CASE 242: ANAGRAMS */

#include <string>
#include <algorithm> // std::sort

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        
        size_t ssize = s.size();
        size_t tsize = t.size();
        
        if (ssize != tsize) {
            return false; // anagrams are of same length
        }
        else {
            // anagrams have the same elements, so sorting helps with matching
            std::sort(s.begin(), s.end());
            std::sort(t.begin(), t.end());
            for (size_t i = 0; i < ssize; ++i) {
                if (s[i] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
