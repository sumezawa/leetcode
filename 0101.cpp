/* CASE 101: Symmetric Tree */

#include <queue> // iterative check

class Solution {
  private:
    struct TreeNode {
        uint32_t val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(uint32_t x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(uint32_t x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };
  public:
    bool iterative_symmetric(TreeNode* root) {
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(root);
        while(!(nodes.empty())) {
            TreeNode* n1 = nodes.front();
            nodes.pop();
            TreeNode* n2 = nodes.front();
            nodes.pop();
            if (!n1 && !n2) {
                continue; // continue to next iteration (skip current)
            }
            else if ((!n1 && n2) || (n1 && !n2) || (n1 && n2 && (n1->val != n2->val))) {
                return false;
            }
            else { // check next subtrees
                nodes.push(n1->left);
                nodes.push(n2->right);
                nodes.push(n1->right);
                nodes.push(n2->left);
            }       
        }
        return true;
    }
    
    bool recursive_symmetric(TreeNode* root) {
        return symmetric_helper(root,root);
        
    }
    
    bool symmetric_helper(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2) {
            return true;
        }
        if ((!n1 && n2) || (n1 && !n2)) {
            return false;
        }
        
        // n1 and n2 are nonempty; check its values first, then its subtrees
        return (n1->val == n2->val) && symmetric_helper(n1->left, n2->right) && symmetric_helper(n1->right, n2->left);
    }
};
