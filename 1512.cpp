/* CASE 1512: OCCURENCES OF FORWARD-TIME MATCHING ELEMENT PAIRS */

#include <unordered_map>
#include <vector>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int ans = 0;
        std::unordered_map<int, int> count; // for elements, stores occurences on the fly
        for (int a : nums) {
            ans += count[a]++;
        }
        return ans;
    }
};

// 1 2 3 1 1 3 -> keys in the hash table
// ans += 0 (1 has 1)
// ans += 0 (2 has 1)
// ans += 0 (3 has 1)
// ans += 1 (1 has 2)
// ans += 2 (1 has 3)
// ans += 1 (3 has 2)
