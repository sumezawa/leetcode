/* CASE 374: GUESS NUMBER */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int mid;
        int dir; // direction to go
        while (low <= high) {
            mid = low + ((high - low) / 2);
            dir = guess(mid);
            if (dir < 0) {
                high = mid - 1; // guess lower
            }
            else if (dir > 0) {
                low = mid + 1; // guess higher
            }
            else {
                return mid; // value found
            }
        }
        return -1; // not found
    }
};
