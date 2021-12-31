/* CASE 1026: MAXIMUM DIFFERENCE BETWEEN TREE NODES */

/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

*/

#include <cmath>

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return max_difference(root, root->val, root->val); // root->val is a stub value
    }
    
    // recursive helper function
    int max_difference(TreeNode* node, int current_min, int current_max) {
        // base case (leaves of the tree)
        if (node == nullptr) {
            return current_max - current_min;
        }
        
        // recursive case (intermediate nodes of the tree)
        current_min = std::min(current_min, node->val);
        current_max = std::max(current_max, node->val);
        return std::max(max_difference(node->left, current_min, current_max),
                        max_difference(node->right, current_min, current_max));
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
*/
