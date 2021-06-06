/* CASE 1480: RUNNING SUM */

class Solution {
public:
    // RUNNING SUM VECTOR 
    vector<int> runningSum(vector<int>& nums) {
        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            *it += *(it - 1);
        }
        return nums;
    }
};
