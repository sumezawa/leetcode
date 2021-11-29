/* CASE 721: MERGE ACCOUNTS */

/* CONSTRAINTS
Given a list of accounts where each element accounts[i] is a list of strings, 
where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. 
Two accounts definitely belong to the same person if there is some common email to both accounts. 
Note that even if two accounts have the same name, they may belong to different people as people could have the same name. 
A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: 
the first element of each account is the name, and the rest of the elements are emails in sorted order. 
The accounts themselves can be returned in any order.
*/

/* DATA STRUCTURES AND ALGORITHMS
Disjoint Set: group (merge) accounts (make finding and merging accounts inverse Ackermann time)
Hash Table: map unique accounts to their multiple emails (make finding those accounts O(1) time)
Sort: sort all emails in each account in order

Each account is an array with variable k elements (grows with number of emails).
*/

/* ASYMPTOTIC COMPLEXITY (for n accounts, k maximum account length):
    - O(nklognk) Time: (due to sort; we omit the inverse Ackermann time for merge/find, and other operations)
    - O(nk) Space: (due to storing all accounts and their multiple emails in disjoint sets and a few hash tables)
*/

#include <algorithm> // omit if you write your own O(nklognk) time, O(lognk) space string sorter
#include <cstddef> // std::size_t
#include <string> // std::string::size()
#include <unordered_map> // omit if you write your own O(1) time, O(n) space hash table
#include <vector> // omit if you write your own dynamic array


/* DISJOINT-SET with PATH COMPRESSION and UNION-BY-SIZE */
class disjoint_set {
    public:
        // CONSTRUCTOR (internally defined)
        disjoint_set(int cardinality) : rep(cardinality), size(cardinality) {
            for (std::size_t i = 0; i < cardinality; ++i) {
                rep[i] = i;
                size[i] = 1;
            }
        }
        void ds_merge() {}
        int ds_find() {}
    
    private:
        std::vector<int> rep;
        std::vector<int> size;
};

class Solution {
    public:
        std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) {
            std::size_t list_size = accounts.size();
            disjoint_set ds(list_size);
            
            std::vector<std::vector<std::string>> merged_list;
            return merged_list;
        }
};
