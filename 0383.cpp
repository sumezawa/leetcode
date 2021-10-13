/* CASE 383: LETTER BANK */

#include <string>
#include <unordered_map> // LETTER BANK

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        // SPECIAL CASE
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        
        // STANDARD CASE
        std::unordered_map<char, int> letter_bank;
        std::string::iterator it = magazine.begin();
        while (it != magazine.end()) {
            if (letter_bank.find(*it) != letter_bank.end()) {
                ++letter_bank[*it];
            }
            else {
                letter_bank[*it] = 1;
            }
            ++it;
        }
        
        it = ransomNote.begin();
        while (it != ransomNote.end()) {
            if (letter_bank.find(*it) != letter_bank.end()) {
                if (letter_bank[*it] > 0) {
                    --letter_bank[*it];
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
            ++it;
        }
        return true;
    }
};
