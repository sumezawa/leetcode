/* CASE 217: CONTAINS DUPLICATE */


// Why is std::sort faster than the hash table? Probably Asymptotics.
// https://douglasorr.github.io/2019-09-hash-vs-sort/article.html

#include <unordered_set>
// #include <algorithm>
#include <vector>

// we only need to know if an element is present
// if it is present and we encounter it again
// it is a duplicate and we can return true

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        /*
        std::sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); i != nums.end() - 1; ++i) {
            if (*i == *(i + 1)) {
                return true;
            }
        }
        return false;
        
        */
        std::unordered_set<int> set;
        for (int i : nums) {
            // unique key
            if (set.find(i) == set.end()) {
                set.insert(i);
            }
            // duplicate key
            else {
                return true;
            }
        }
        return false;
    } 
}; 
