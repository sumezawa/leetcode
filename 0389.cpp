/* CASE 389: FIND EXTRA CHARACTER */

#include <string>

// string t is a reshuffled string with an additional char
// find that char and return it

class Solution {
public:
    char findTheDifference(string s, string t) {
        // O(n) Time, O(1) Space
        
        // make a 26-int array to store counts for each array
        // 0 position is for 'a', 25 position is for 'z'
        // intialise every element to 0
        int t_count[26] = {0};
        std::string::iterator it = t.begin();
       
        // count the characters in shuffled string t O(n)
        while (it != t.end()) {
            ++t_count[*it - 'a'];
            ++it;
        }
        
        it = s.begin();
        // subtract the characters in string s O(n)
        while (it != s.end()) {
            --t_count[*it - 'a'];
            ++it;
        }
        
        // return char such that the int array entry is 1 O(1)
        for (size_t i = 0; i < 26; ++i) {
            if (t_count[i] == 1) {
                return (char)('a' + i);
            }
        }
        
        // there is a guarantee condition by LeetCode
        // such that there is always a duplicate
        // if not, then we can still just return a dummy:
        return '0';
    }
};
