/* CASE 448: FIND MISSING ELEMENTS OF SEQUENCE */

#include <unordered_set>
#include <vector>

class Solution {
public:
    // O(n) Time, O(1) Space
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    
    }
    
    // O(n) Time, O(n) Space
    std::vector<int> on_findDisappearedNumbers(std::vector<int>& nums) {
        // insert all the elements into the look-up table
        std::unordered_set<int> ltable;
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            ltable.insert(*it);
        }
        
        // iterate from 1 to the largest element (in this case, the size of the array)
        // any of which that don't appear in the look-up table
        // is 'missing' so you insert it to our missing array
        std::vector<int> missing;
        for (int i = 1; i <= nums.size(); ++i) {
            if (ltable.find(i) == ltable.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};
