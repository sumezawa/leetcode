/* CASE 136: FIND SINGLETON IN AN ARRAY */

#include <unordered_set> // O(1) Lookup Table, insert(), erase()
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }
        
        // Average O(1) Space
        // Worst O(n) Space
        std::unordered_set<int> ltable;
        std::vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            if (ltable.find(*it) == ltable.end()) {
                ltable.insert(*it);
            }
            else {
                ltable.erase(*it);
            }
            ++it;
        }

        for (auto x : ltable) {
            return x;
        }  
        
        // for integers (not ADTs / templates)
        // there is an O(1) space implementation
        // using bitwise XOR:
        /*
        int ans = nums[0];
        for (int i : nums) {
            ans = (ans ^ nums[i]);
        }
        return ans;
        */
        
        return 0;
    }
};
