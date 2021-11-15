/* CASE 700: SEARCH IN BST */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST_re(TreeNode* root, int val) {
        
        if (root == nullptr || root->val == val) { // BASE CASE
            return root;
        }
        
        if (root->val < val) { // val is larger than parent
            return searchBST(root->right, val); // check larger children
        }
        else {
            return searchBST(root->left, val); // check smaller children
        }        
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        while (temp != nullptr) {
            if (temp->val < val) {
                temp = temp->right;    
            }
            else if (temp->val > val) {
                temp = temp->left;
            }
            else {
                return temp;
            }
        }
        
        return temp; // element not found -> return nullptr
    }
    
};
