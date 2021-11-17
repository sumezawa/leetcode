/* CASE 46: ARRAY ELEMENT PERMUTATIONS, DISTINCT ELEMENTS */

// enumerating all possible solutions = backtracking
// permutations require us to consider every single solution

// #include <unordered_map> 
// permutations contain too little elements to yield asymptotic O(1) behaviour
// it is wasted space (compared to a bool array)

#include <vector>


class Solution {
public:
    // CONSTRAINTS
    // 1 <= nums.length <= 6
    // -10 <= nums[i] <= 10
    // all elements are distinct
    
    // 0 ms, 7.5MB, Bool Array
    
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> set;
        std::vector<bool> used(nums.size(), false);
        std::vector<int> p;
        backtrack(set, used, 0, p, nums);
        return set;
    }
    
    void backtrack(std::vector<std::vector<int>>& set,
                   std::vector<bool>& used, size_t p_length,
                   std::vector<int>& p, std::vector<int>& nums) {
        // BASE CASE (permutation creation completed)
        if (p_length == nums.size()) {
            set.push_back(p);
            return;
        }
        
        // RECURSIVE CASE (permutation creation in progress)
        for (size_t i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue; // don't insert duplicates for permutation
            }
            used[i] = true;
            p.push_back(nums[i]);
            backtrack(set, used, p_length + 1, p, nums);
            used[i] = false;
            p.pop_back();
        }
        
        return;
    }

    // 8 ms, 8.6 MB, Hash Tables
    
    std::vector<std::vector<int>> slow_permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> p;
        std::unordered_map<int, unsigned short> htable; // hash table, maps nums elements to their indices
        std::vector<int> pm;
        slow_backtrack(p, htable, pm, nums);
        return p;
    }
    
    void slow_backtrack(std::vector<std::vector<int>>& set, 
                   std::unordered_map<int, unsigned short>& htable,
                   std::vector<int>& subset, std::vector<int>& nums) {
        // BASE CASE (permutation creation completed)
        if (htable.size() == nums.size()) {
            set.push_back(subset);
            return;
        }
        
        // RECURSIVE CASE (permutation creation in progress)
        for (size_t i = 0; i < nums.size(); ++i) {
            if (htable.find(nums[i]) != htable.end()) {
                continue; // don't insert duplicates for permutation
            }
            htable[nums[i]] = i;
            subset.push_back(nums[i]);
            slow_backtrack(set, htable, subset, nums);
            htable.erase(nums[i]);
            subset.pop_back();
        }
        
        return;
    }
};

// A little visualisation
// suppose nums = [1,2,3]
// the order of operations is as follows:
// i = 0, nums[0] = 1, [1], enter first recursive call
// i = 0, nums[0] = 1, but we do not add [1] because we allow no duplicates. continue
//     continue implies we go to the next for-loop iteration (do not enter recursive call)
//     i = 1, nums[1] = 2, [1,2], enter second recursive call
// similar to above, but i = 2, and we get [1,2,3], enter third recursive call
// [[1,2,3]], base case, return, resume second recursive call
// backtrack, so pop '3' from the htable / subset the for loop ends, return. resume first recursive call
// [[1,2,3]]; [1,2]
// backtrack, so pop '2' from the htable / subset.
// [[1,2,3]]; [1]
// i = 2, nums[2] = 3, [[1,2,3]]; [1,3], enter second recursive call
// i = 0 we skip the insertion of nums[0],
//     i = 1, nums[1] = 2 [[1,2,3]]; [1,3,2]. enter third recursive call
// [[1,2,3],[1,3,2]] base case, return, resume second recursive call
// backtrack, so pop '2' from the htable / subset. [[1,2,3],[1,3,2]]; [1,3]
// i = 2, nums[2] = 3, which is already in the subset, so we skip
// for loop ends, the function returns, resume first recursive call
// backtrack, so pop '3' from the htable / subset. [[1,2,3],[1,3,2]]; [1]
// for loop ends, the function returns, resume the original function call
// backtrack, so pop '1' from the htable / subset. [[1,2,3],[1,3,2]]; []
// i = 1, we now begin the permutations starting with 2.
