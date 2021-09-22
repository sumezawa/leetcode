/* CASE 14: TRIES FOR LONGEST COMMON PREFIX */
// aka the one-child policy checker

// faster than 72.13% of LeetCode Entries BUT more memory than 88.84% of LeetCode Entries
// checked with valgrind, no memory leaks for the test cases below, although I only tested three cases haha
// solution assumes strings are unique (do not repeat)

#include <string>
#include <vector>

// using a Trie, which traces etymological origins from 'retrieval',
// we can keep track of each string's character combinations

class TrieNode {
    public:
        bool end; // is this node the end of the word? 
        TrieNode* children[26]; // 26 = # of lower-case english letters
        TrieNode() : end(false), children{} {} // by default, initialises to nullptr
};

// because I forgot OOP in C++, :(
// I wrote an external destructor.
// it is recursive because I don't know how to do iterative,
// and I usually just take the least path of resistance when coding :/

void delete_trie_helper(TrieNode* node) {
    if (!(node->end)) {
        for (uint8_t i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                delete_trie_helper(node->children[i]);
            }
        }
    }
    
    if (node != nullptr) {
        delete node;
    }
}

void delete_trie(TrieNode* root) {
    delete_trie_helper(root);
}

// the layer such that a node has more than one child
// is the last character of the longest common prefix
// if the root node itself has more than one child
// then return ""

class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            // SPECIAL CASE: EMPTY ARRAY
            if (strs.size() < 1) return "";
            
            // STANDARD CASE (for singleton array, just return that string)
            TrieNode* root = new TrieNode;
            TrieNode* trav;
            
            // construct Trie
            for (auto it = strs.begin(); it != strs.end(); ++it) {
                trav = root;
                for (auto& c : *it) {
                    int index = c - 'a';
                    if (trav->children[index] == nullptr) {
                        trav->children[index] = new TrieNode;
                    }
                    trav = trav->children[index];
                }
                
                trav->end = true;
            }
            
            trav = root;
            std::string prefix; // by default an empty string
            uint8_t common_index; // index for common char, from 0 to 26
            bool one_child = false;
            
            while (!trav->end) {
                for (uint8_t index = 0; index < 26; ++index) {
                    if (trav->children[index] != nullptr) {
                        if (!one_child) {
                            common_index = index;
                            one_child = true;
                        }
                        else {
                            // terminate if commonality ends
                            delete_trie(root);
                            return prefix;
                        }
                    }
                }
                
                // if for loop terminates normally,
                // there was only one child, hence
                prefix += ('a' + common_index);
                
                // reset boolean, go to the next level
                one_child = false;
                trav = trav->children[common_index];
            }
            
            delete_trie(root);
            return prefix;
        }
};

// TEST CODE
int main() {
    Solution s;
    // test standard
    std::vector<std::string> bruh{"mitchmcconnell", "bruh", "bro", "bruhgskiy", "bruhgman", "broskii", "brother"};
    std::cout << s.longestCommonPrefix(bruh) << std::endl;
    bruh.clear();
    // test singleton
    bruh.push_back("a");
    std::cout << s.longestCommonPrefix(bruh) << std::endl;
    bruh.clear();
    // test no common prefix
    bruh.push_back("a");
    bruh.push_back("b");
    bruh.push_back("thy mother");
    std::cout << s.longestCommonPrefix(bruh) << std::endl;
    return 0;
}
