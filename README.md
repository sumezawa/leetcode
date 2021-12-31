# average programmer's leetcode solutions
My C++ Leetcode Solutions


As of 9 December 2021, 
- Easy: 56 of 532
- Medium: 13 of 1115
- Hard: 1 of 446


have been completed and archived here. I have more accepted code on LeetCode than on this repository, but I don't post submissions on GitHub unless I have understood every line of code in the problem at some point.


For example, in LeetCode Problem 0047, Permutations of Non-Unique Elements, I am still stuck on the if condition that determines a redundant permutation; therefore I have not yet uploaded the code here.

        // RECURSIVE CASE (permutation creation in progress)
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (used[i] || (i > 0 && nums[i - 1] == nums[i] && used[i - 1])) { // ????? WOT
                continue; // skip redundant permutation
            }
            used[i] = true;
            p.push_back(nums[i]);
            backtrack(set, used, p_length + 1, p, nums);
            used[i] = false;
            p.pop_back();
        }

You are welcome to adapt or copy my code; if you do, please reference the .cpp file and the repository.
