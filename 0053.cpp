/* CASE 53: MAXIMUM SUBARRAY */

#include <cmath>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_sum = -2147483648;
        int temp_sum = 0;
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            temp_sum += *it;
            max_sum = std::max(max_sum, temp_sum); // this is faster than if-else statement
            if (temp_sum < 0) {
                temp_sum = 0;
            }
        }
        return max_sum; // a simple modification can also keep track of the subarray indices.
    }
};

// from CS 130A Lecture:
// 1Q) why do max subarrays never start or end with a negative number?
// 1A) because you can start or end with a positive number and have a larger subarray.
//
// 2Q) why do max subarrays never have a negative prefix?
// 2A) we can remove that prefix and have a larger subarray.
//
// 3Q) we keep track of a sum and the continguous subarray until the
//     sum is less than zero. the best sum is either this one, or the
//     next sum that we begin counting from the new subarray. why?
// 3A) first, the former subarray is now negative, so it is a negative prefix
//     which is better removed.
//
// 4Q) a stronger assumption is that the new subarray cannot contain any 
//     part of the former subarray. prove this statement:
// 4A) Proof: suppose a portion of the old subarray and the new subarray
//     was the max subarray. Suppose
//     a_i = start of old
//     a_p = start of partial (start of max)
//     a_j = end of old
//     It is obvious that a_j is the index such that the subarray is negative.
//     This implies that the sum of a_i to a_k, for i <= k <= j is positive.
//     This implies that despite the max subarray starting at a_p, there is 
//     a portion a_i to a_{p - 1}, a prefix, that could be appended to the 
//     max subarray to make a better subarray. (This contradicts the assumption
//     that the max subarray is in fact the max subarray.)
//
//     Hence, the new subarray, a candidate max subarray, does not contain
//     any parts of other subarray candidates.
//
// 5Q) what is the max subarray?
// 5A) we don't necessarily keep track of the subarray, but the maximum sum attained.
//     When we move onto a new subarray, we just clear the negative sum so far.
