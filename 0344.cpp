/* CASE 344: REVERSE CHAR ARRAY O(1) SPACE */

#include <algorithm>
// commented out version is still O(1), but it expends a byte more

class Solution {
public:
    void reverseString(vector<char>& s) {
        uint16_t mid = s.size() / 2;
        // char temp;
        for (uint16_t i = 0; i < mid; ++i) {
            std::swap(s[i], s[len - i - 1]);
            // temp = s[i];
            // s[i] = s[len - i - 1];
            // s[len - i - 1] = temp;
        }
    }
};
