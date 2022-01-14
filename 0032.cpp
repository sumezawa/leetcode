/* CASE 32: LONGEST VALID SUBSTRING */

#include <string>

// O(n) time, O(1) space
// closed parentheses

class Solution {
public:
    int longestValidParentheses(std::string s) {
        
        // special case
        if (s == "") {
            return 0;
        }
        
        
        // standard case
        int left = 0;
        int right = 0;
        int max = 0;
        
        // first pass (left to right)
        for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
            if (*it == '(') {
                ++left;
            }
            else {
                ++right;
            }
            
            if (left == right) {
                if (left + right > max) {
                    max = left + right;
                }
            }
            else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        
        // this code fails for "(()" without the second pass (right to left)
        // specifically because left, right are reset.
        left = 0;
        right = 0;
        for (std::string::iterator it = s.end() - 1; it != s.begin(); --it) {
            if (*it == '(') {
                ++left;
            }
            else {
                ++right;
            }
            
            if (left == right) {
                if (left + right > max) {
                    max = left + right;
                }
            }
            else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        return max;
    }

};

/* PROOF

The claim that we would like to prove is that one or both passes
suffices to yield the longest valid substring.

Proof:
Let the longest valid substring be s[i,j], for some i < j.
In the left-to-right (forward) pass, we assumed the invariant left >= right.
We reset left, right if the invariant was violated.
After processing index i - 1, consider the following cases:

CASE 1: left == right
substring s[i,j] has an equal number of '(' and ')'.
After processing index j, left == right.
The forward pass found the longest valid substring.

CASE 2: left > right
substring s[i,j] has an equal number of '('and ')'.
After processing index j, left > right.
The forward pass does not find the longest valid substring.

In the right-to-left (backward) pass, we assumed the invariant right >= left.
We reset left, right if the invariant was violated.
After processing index j + 1, consider the following cases:

CASE 1: left == right
substring s[j, i] has an equal number of '(' and ')'.
After processing index j, left == right.
The forward pass found the longest valid substring.

CASE 2: left < right
(CRUX OF THE PROOF)
Note, in the forward pass, processing index i - 1 yielded two cases,
and we assume that the forward pass failed to find the longest valid substring
because left > right.

For the backward pass, processing index j + 1 and yielding right > left 
will result in failure to find the longest valid substring.

It suffices to show that both cannot happen at the same time to prove that
one or both of the passes succeed in yielding the longest valid substring.

Suppose both passes fail.
Notice that if both passes fail, left > right at i - 1 implies s[i] == '(',
otherwise there would exist some i_0 < i such that s[i_0, i) is valid, and
s[i_0,j] is also valid. If right > left at j + 1, then similarly s[j] == ')' and
there exists some j_f > j.
Therefore s[i,j] can be expanded to s[i_0, j_f]. This contradicts the longest valid substring assumption.

Hence, one or more passes suffice.
*/
