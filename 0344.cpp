/* CASE 344: REVERSE CHAR ARRAY O(1) SPACE */

// we could have used std::swap

class Solution {
public:
    void reverseString(vector<char>& s) {
        uint16_t len = s.size();
        uint16_t mid = len / 2;
        char temp;
        for (uint16_t i = 0; i < mid; ++i) {
            temp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = temp;
        }
    }
};
