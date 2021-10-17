/* CASE 387: EARLIEST UNIQUE CHARACTER */

#include <string>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        int size = s.size();
        // SPECIAL CASE
        if (size == 1) {
            return 0;
        }
        
        // STANDARD CASE
        std::unordered_map<char, int> htable;
        for (size_t i = 0; i < size; ++i) {
            if (htable.find(s[i]) == htable.end()) {
                htable[s[i]] = i;
            }
            else {
                htable[s[i]] = -1;
            }
        }
        
        int first_unique = 100000; // max input length
        auto it = htable.begin();
        while (it != htable.end()) {
            if ((*it).second >= 0 && (*it).second < first_unique) {
                first_unique = (*it).second;
            }
            ++it;
        }
        
        if (first_unique == 100000) {
            return -1;
        }
        else {
            return first_unique;
        }
    }
};
