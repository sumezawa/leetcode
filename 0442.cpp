/* CASE 442: FIND PAIRS IN AN ARRAY */
// very similar CASE 136, FIND SINGLETON IN AN ARRAY */

#include <unordered_set> // O(1) Look-Up Table, insert(), erase()
#include <vector>

#include <cmath> // for integer array

class Solution {
public:
    
    // This solution works for abstract data types other than
    // integers; but if it were just integers (and there were
    // additional conditions, there are better algorithms
    std::vector<int> findDuplicates2(std::vector<int>& nums) {
        
        // Average O(1) Space
        // Worst O(n) Space
        std::unordered_set<int> ltable;
        std::vector<int>::iterator it = nums.begin();
        
        std::vector<int> dupes;
        
        while (it != nums.end()) {
            if (ltable.find(*it) == ltable.end()) {
                ltable.insert(*it);
            }
            else {
                ltable.erase(*it); // can delete, because elements no more than twice
                dupes.push_back(*it); // insert to set of all pair elements
            }
            ++it;
        }
        
        return dupes;
    }
    
    // If we were to add the condition that:
    // 1) array is length n
    // 2) elements in array are in the range 1 to n
    // 3) elements appear once or twice
    // then there is a guaranteed O(1) Space Algorithm:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> dupes;
        for (auto i : nums) {
            i = std::abs(i);
            if (nums[i - 1] < 0) {
                dupes.push_back(i);
            }
            nums[i - 1] *= -1;
        }
        return dupes;
    }
};
