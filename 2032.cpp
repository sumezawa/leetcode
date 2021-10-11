/* CASE 2032: MULTIPLE MEMBERSHIP IN ARRAY */

#include <unordered_map> // hash table solution
#include <unordered_set> // look-up table solution
#include <vector>


class Solution {
public:
    std::vector<int> multiple_membershipLT(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3) {
        
        // GET SETS
        std::unordered_set<int> set1;
        std::vector<int>::iterator it = nums1.begin();
        while (it != nums1.end()) {
            if (set1.find(*it) == set1.end()) {
                set1.insert(*it);
            }
            ++it;
        }
        
        std::unordered_set<int> min2; // set of elements with membership in multiple arrays
        std::unordered_set<int> set2;
        it = nums2.begin();
        while (it != nums2.end()) {
            if (set2.find(*it) == set2.end()) {
                set2.insert(*it);
                if (set1.find(*it) != set1.end()) {
                    min2.insert(*it); // it doesn't add duplicates so O(1) time is spent for duplicates
                }
            }
            ++it;
        }
        
        std::unordered_set<int> set3;
        it = nums3.begin();
        while (it != nums3.end()) {
            if (set2.find(*it) != set2.end() || set1.find(*it) != set1.end()) {
                min2.insert(*it);
            }
            ++it;
        }
        
        std::vector<int> tot(min2.begin(), min2.end());
        return tot;
        
    }

    std::vector<int> multiple_membershipHT(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3) {
        
        std::unordered_map<int, char> nums;
        std::vector<int>::iterator it = nums1.begin();
        while (it != nums1.end()) {
            if (nums.find(*it) == nums.end()) {
                nums[*it] = 'a'; // value for unique keys found in nums1
            }
            ++it;
        }
        std::vector<int> tot; // elements found in more than one array (category)
        it = nums2.begin();
        while (it != nums2.end()) {
            if (nums.find(*it) == nums.end()) {
                nums[*it] = 'b'; // value for unique keys found in nums2, not in nums1
            }
            else if (nums[*it] == 'a') {
                tot.push_back(*it);
                nums[*it] = 'c'; // 'c' for checked. do not add this key again
            }
            ++it;
        }
        it = nums3.begin();
        while (it != nums3.end()) {
            // only check if found in nums1 or nums2
            if (nums.find(*it) != nums.end()) {
                if (nums[*it] != 'c') {
                    nums.erase(*it); // eliminate from htable
                    tot.push_back(*it);
                }
            }
            ++it;
        }
        
        return tot;
        
    }
};
