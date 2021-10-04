/* CASE 290: PATTERN BIJECTION */

#include <queue>
#include <string>
#include <unordered_map>

// 1 <= pattern.length <= 300
// pattern contains only lower-case Anglais words
// 1 <= s.length <= 3000
// s contains only lower-case English letters and spaces ' '
// s does not contain any leading or trailing spaces
// all words in s are demarcated by a single space ' '

// a simple (to implement) solution
// are two hash tables and an algorithm
// that checks one-to-one and onto

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {

        std::string::iterator i = s.begin();
        std::queue<std::string> words;
        std::string word;
        
        // make array of words
        while (i != s.end()) {
            if (*i == ' ') {
                words.push(word); // first word in will be checked first
                word.clear();
            }
            else {
                word += *i;
            }
            ++i;
        }
        words.push(word);
        
        // cannot compare if pattern / words mismatched size
        if (words.size() != pattern.size()) {
            return false;
        }
        
        std::unordered_map<char, std::string> chartable;
        std::unordered_map<std::string, char> stringtable;
        
        for (char c : pattern) {    // check for bijection
            word = words.front();
            if ((chartable.find(c) == chartable.end()) && 
                (stringtable.find(word) == stringtable.end())) { // key not found
                chartable[c] = word;
                stringtable[word] = c;
            }
            else {
                if (chartable[c] != word || stringtable[word] != c) {
                    return false;
                }
            }
            words.pop();
        }
        return true;
    }
};
