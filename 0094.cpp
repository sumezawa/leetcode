/* CASE 94: DEPTH FIRST SEARCH INTRO */

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

#include <stack> // iterative
#include <vector>

class Solution {
public:
    
    // ITERATIVE
    std::vector<int> inorderTraversalIt(TreeNode* root) {
        std::stack<TreeNode*> stack;
        std::vector<int> list;
        TreeNode* temp = root;
        
        while (temp != nullptr || !(stack.empty())) {
            while (temp != nullptr) {
                stack.push(temp);
                temp = temp->left;
            }
            
            // the stack is DFS iterative
            // - inorder: gradual rightward sweep, frequent leftward depth search 
            // the queue is BFS iterative
            temp = stack.top();
            list.push_back(temp->val);
            temp = temp->right;
            stack.pop();
        }
        return list;
    }
  
    // RECURSIVE
    std::vector<int> inorderTraversalRe(TreeNode* root) {
        std::vector<int> list;
        helper(list, root);
        return list;
    }
    
    // remember to pass by reference, or else the vector is lost!
    // this is not the case for pointers, which store addresses.
    void helper(std::vector<int>& list, TreeNode* root) {
        if (root != nullptr) {
            if (root->left != nullptr) {
                helper(list, root->left);
            }
            
            list.push_back(root->val);
            
            if (root->right != nullptr) {
                helper(list, root->right);
            }
        }
    }
    
};
