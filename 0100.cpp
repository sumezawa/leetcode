/* CASE 100: RECURSIVE BINARY TREE COMPARATOR */

// an iterative comparator will have memory overhead

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // BASE CASES
        
        // TRUE CONDITION
        if (p == nullptr && p == q) {
            return true;
        }
        
        // FALSE CONDITIONS
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        // RECURSIVE CASE (&& means both subtrees must also be the same to return true)
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
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
