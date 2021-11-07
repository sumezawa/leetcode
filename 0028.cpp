/* CASE 28: FIND SUBSTRING */

#include <string>

// 0ms, 100% faster than all LeetCode submissions
// 7MB, 91% lighter than all LeetCode submissions
// surprising results, given this isn't a KMP algorithm (or is it? I'm not sure.)
// something I've noticed is that function call (string.size())
// is faster and less memory consuming than storing the string size as a variable

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        
        // SPECIAL CASES
        if (needle.empty()) {
            return 0; // needle == ""
        }
        
        // STANDARD CASES
        
        unsigned short matches = 0; // # of character matches, in ascending order
        // 0 is the beginning of the candidate substring
        // we increment matches up if the corresponding haystack character matches
        // we return the beginning index of the substring in the haystack when matches = size of needle
        
        unsigned short end = needle.size() - 1; // right end of the sliding window
        // this implementation has a sliding window that starts out as two edges:
        // LEFT END (EMPTY EMPTY EMPTY) RIGHT END
        // such that the left end closes in and approaches the right end
        // LEFT END MATCH MATCH EMPTY RIGHT END
        // if there are matches every time, up to the right end, the window fully closes aka needle is found
        // the window resets to its 'open' state and shifts right if there is a mismatch
        
        while (end < haystack.size()) {
            if (haystack[end - matches] == needle[needle.size() - 1 - matches]) { // CLOSE WINDOW
                if (matches == needle.size() - 1) {
                    return end - matches;
                }
                else {
                    ++matches; 
                }
            }
            else { // RESET WINDOW TO FULLY OPEN, SHIFT WINDOW
                matches = 0;
                ++end;
            }
        }
        
        return -1;
    }
};
