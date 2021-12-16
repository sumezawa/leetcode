/* CASE 1672: MATRIX - SUM OF ROW */

#include <vector>


// return the sum of the row with maximum sum of its columns

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& matrix) {
        int max_sum = 0;
        int temp = 0;
        
        // for each row
        for (std::vector<std::vector<int>>::iterator rit = matrix.begin(); rit != matrix.end(); ++rit) {
            // for each column
            for (std::vector<int>::iterator cit = rit->begin(); cit != rit->end(); ++cit) {
                temp += *cit;
            }
            if (max_sum < temp) {
                max_sum = temp;
            }
            temp = 0;
        }
        
        return max_sum;
    }
};
