/* CASE 6: ZIG-ZAG STRINGS */

#include <stdint.h>
#include <iterator> // std::distance
#include <string>

class Solution {
public:
    std::string convert(std::string s, int rows) {
        
        // SPECIAL CASES:
        if (rows < 2) {
            return s;
        }
        
        // STANDARD CASES:
        // Consider the following pattern:
        // 5 rows = 3 mid, rev = 8
        // 4 rows = 2 mid, rev = 6
        // 3 rows = 1 mid, rev = 4
        // 2 rows = 0 mid, rev = 2
        
        std::vector<std::string> strings(rows,""); // keeps track of all rows
        uint16_t revolution = (rows - 1) * 2; // # characters to return to first row
        uint16_t offset = 0;
        
        std::string::iterator it = s.begin();
        while(it != s.end()) {
            offset = std::distance(s.begin(), it) % revolution;
            if (offset < rows) {
                strings[offset] += *it; // same column characters
                // e.g rows = 4, revolution = 6
                // offset = 0 1 2 3 (same column)
            }
            else {
                strings[revolution - offset] += *it; // ascending diagonal characters
                // e.g rows = 4, revolution = 6
                // offset = 4 5 (corresponds to rows 2 1)
            }
            ++it;
        }
        
        std::string output;
        for (std::string& str : strings) {
            output += str;
        }
        
        return output;
    }
};
