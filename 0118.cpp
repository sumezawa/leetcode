/* CASE 118: PASCAL'S TRIANGLE */

#include <vector>
// faster than 100% of all submissions.
// lighter than 70% of all submissions.

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> pascal;
        pascal.push_back(std::vector<int>{1});
        
        if (numRows > 1) {
            pascal.push_back(std::vector<int>{1,1});    
        }
        
        if (numRows > 2) {
            int i = 3;
            while (i <= numRows) {
                std::vector<int> row;
                row.reserve(i);
                row.push_back(1);
                for (size_t j = 1; j < i - 1; ++j) {
                    row.push_back(pascal.back()[j - 1] + pascal.back()[j]);
                }
                row.push_back(1);
                pascal.push_back(row);
                ++i;
            }            
        }
        
        return pascal;

    }
};
