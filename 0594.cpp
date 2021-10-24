/* CASE 594: LONGEST HARMONIOUS SUBSEQUENCE */

#include <unordered_map>
#include <vector>

// what is a HARMONIOUS SUBSEQUENCE
// - subsequence of an array where difference between the max and min values is 1
// 
// what is a SUBSEQUENCE
// - a sequence that can be derived by deleting some or no elements
// - must not change the order of the array


// Due to the test cases having at most
// array length no greater than 20000
// key from -10^9 to 10^9
// the sort O(nlogn) algorithm is faster than hash maps

// O(n) Time, O(n) Space
class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<int, int> htable;
        int len = 0;
        for (int num : nums) {
            // first, increment the hash table value
            ++htable[num];
            // check n - 1 case
            if (htable.find(num - 1) != htable.end()) {
                len = maximum(len, htable[num] + htable[num - 1]);
            }
            // check num + 1 case as well
            if (htable.find(num + 1) != htable.end()) {
                len = maximum(len, htable[num] + htable[num + 1]);
            }
        }
        return len;
    }
    
    // HELPER FUNCTION
    int maximum(int a, int b) {
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
};

// EXPLANATION OF THE HASH TABLE +/- 1 CHECKER:
// consider if num - 1, or num + 1 exists
// if both false, len remains len (disregard this element in subsequence)
// if both true, len equals
// = max(len, sub len with num + sub len with num + 1, sub len with num + sub len with num - 1)
// if only one of them true,
// = max(len, sub len with num + sub len with num +/- 1)
//
// we can evaluate len this way because subsequences can delete any number of elements in between
// and this method preserves the order (it retains memory of the frequency of all elements prior)

/*

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]
Output: 2

Example 3:

Input: nums = [1,1,1,1]
Output: 0

*/
