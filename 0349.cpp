/* CASE 349: SET INTERSECTION */

#include <vector>
#include <unordered_set> // O(1) Time lookup table

// The best is O(n) Time, O(n) Space

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set;
        for (auto i : nums1) {
            if (set.find(i) == set.end()) {
                set.insert(i);
            }
            // if already inside, don't do anything
        }
        
        std::vector<int> intersection_set;
        for (auto j : nums2) {
            if (set.find(j) != set.end()) {
                intersection_set.push_back(j);
                set.erase(j);
            }
        }
        
        return intersection_set;
    }
};
