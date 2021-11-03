/* CASE 1160: WORDS CONSTRUCTABLE */

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::unordered_map<char, int> bank;
        for (char c : chars) {
            ++bank[c];
        }
        
        int sum; // sum of characters of words possible
        bool accept;
        std::unordered_map<char, int> tempbank = bank;
        
        for (std::string word : words) {
            accept = true;
            for (char c : word) {
                if (tempbank.find(c) == tempbank.end()){
                    accept = false;
                    break;
                }
                else {
                    if (tempbank[c] == 0) {
                        accept = false;
                        break;
                    }
                    else {
                        --tempbank[c];
                    }
                }
            }
            if (accept) {
                sum += word.size();
            }
            tempbank = bank;
        }
        return sum;
    }
};
