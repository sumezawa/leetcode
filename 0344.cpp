/* CASE 344: REVERSE CHAR ARRAY O(1) SPACE */

// we could have used std::swap from #include <algorithm>

class Solution {
public:
    void reverseString(vector<char>& s) {
        uint16_t mid = s.size() / 2;
        char temp;
        for (uint16_t i = 0; i < mid; ++i) {
            // std::swap(s[i], s[len - i - 1]);
            temp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = temp;
        }
    }
};
