/* CASE 49: GROUP ANAGRAMS */

#include <string>
#include <unordered_map>
#include <vector>

// CONSTRAINTS
// - Array is no longer than 10000 Words
// - String is no longer than 100 Characters
// - All words are lowercase

class Solution {
public:
    
    // O(n) Space (due to hash table), O(n) Time
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> htable;
        std::string::iterator it;
        std::string frequency; 
        // array to store frequency of characters ('spectrum')
        
        // the reason why we use char frequency over something like an integer array is 
        // simply because the char array takes less memory, and we can convert the
        // spectrum to a string, for easy checking in the hash table
        
        // 'Counting Sort' ... not O(n) if there were not finitely unique elements
        for (std::string s : strs) { // access each word, count frequency of characters
            it = s.begin();
            frequency = "!!!!!!!!!!!!!!!!!!!!!!!!!!";
            while (it != s.end()) { // find character spectrum of each word
                ++frequency[*it - 'a']; // increment character counts
                ++it;
            } // frequency count does not exceed 100 operations (string length), hence approx O(100n) = O(n)
            std::string word(frequency); // create the key
            htable[word].push_back(s); // put the original string s into its associated array
        } 
        
        std::vector<std::vector<std::string>> groups;
        for (auto e : htable) { // O(n) time, access each group
            groups.push_back(e.second);
        }
        
        return groups;
    }
};
