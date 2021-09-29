/* CASE 1929: DUPLICATE AND APPEND AN ARRAY */

#include <vector>


class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
       std::vector<int> ans; 
       for (int i = 0; i < 2; ++i) {
           for (auto it = nums.begin(); it != nums.end(); ++it) {
               ans.push_back(*it);
           }
       }
       return ans;
    }
};
