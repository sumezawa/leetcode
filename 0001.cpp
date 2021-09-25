/* CASE 1: TWO-SUM PROBLEM */

/*
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.You can return the answer in any order.
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    /* O(n) IMPLEMENTATION WITH HASH TABLE */
    std::vector<int> twoSum(std::vector<int>& nums, int& target) {
        // C++ RB-TREE = MAP (ordered key and value)
        // C++ HASH TABLE = UNORDERED MAP (unordered key and value)
        // C++ LOOKUP TABLE = UNORDERED SET (presence or absence)
        std::unordered_map<int, int> htable; // h_key = array's value, h_value = array's index
        for (size_t num_index = 0; num_index < nums.size(); ++num_index) {
            // we try to find whether a complement of some array value exists in the array
            // we use the hash table to find the complement in O(1) time
            // if it exists, then we return the array index and the complement index
            if (htable.find(target - nums[num_index]) != htable.end()) {
                return std::vector<int>{(int)num_index, htable[target - nums[num_index]]};
            }
            // update the hash table with the array's current value
            htable[nums[num_index]] = num_index;
        }
        // at the worst case the loop traverses the entire array
        // (the case that which there is no valid pair)
        return std::vector<int>{}; // return an empty array if no such pair exists
    }
    
    // some comments
    // the index is size_t, but the return value is an int-vector, so we need to make the index int
    // the hashtable update must be after checking for the complement, not before it
};
