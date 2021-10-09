/* CASE 278: BINARY SEARCH */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// find the first 'bad' element in a sorted array
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1; // for arrays 0
        int right = n; // for arrays n - 1
        int mid;
        while (left < right) {
            // mid = (left + right) / 2; causes integer overflow :(
            // according to geeksforgeeks, this is a common workaround
            // for middle-needing algorithms (like divide and conquer algorithms)
            mid = left + ((right - left) / 2);
            if (isBadVersion(mid)) {
                right = mid; // search first half
            } 
            else {
                left = mid + 1; // search right half
            }
        }
        return left;
    }
};
