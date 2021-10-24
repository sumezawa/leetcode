/* CASE 205: ISOMORPHIC STRINGS */

#include <string>
#include <unordered_map>

// what is ISOMORPHISM?
// - all occurrences of a character is replaced with another character (onto)
// - the order of characters are preserved
// - no two characters map to the same character (one-to-one)
// - a character could map itself

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        // for transformation T: U -> V
        std::unordered_map<char, char> U;
        std::unordered_map<char, char> V;
        std::string::iterator sit = s.begin();
        std::string::iterator tit = t.begin();
        while (sit != s.end()) {
            if (U.find(*sit) == U.end()) {
                if (V.find(*tit) == U.end()) {
                    U[*sit] = *tit;
                    V[*tit] = *sit;
                }
                else {
                    // if domain char is not found
                    // yet range char is found, then
                    return false;
                }
            }
            else {
                if (V.find(*tit) != V.end()) {
                    if (U[*sit] == *tit, V[*tit] == *sit) {
                        // proceed as usual
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            ++sit;
            ++tit;
        }
        return true;
    }
};
