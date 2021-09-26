/* CASE 171: DECODING: SPREADSHEET COLUMNS */
// decoding spreadsheet column letters to column numbers

#include <string>
#include <cmath>



class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int column = 0;
        size_t end = columnTitle.size();            
        column += (columnTitle[end - 1] - 'A' + 1);
        // the numbers are in base 26, hence
        for (int i = 1; i < end; ++i) {
            column += (columnTitle[end - i - 1] - 'A' + 1) * pow(26,i);

        }
        return column;
    }
};
