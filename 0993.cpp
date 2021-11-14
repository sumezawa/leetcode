/* CASE 993: BINARY TREE COUSINS */

#include <queue> // BFS
#include <utility> // std::pair<TreeNode*, std::pair<char, int>>, consumes a lot of memory

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
    bool isCousins(TreeNode* root, int x, int y) {
        bool x_missing = true;
        bool y_missing = true;
        char x_depth = '!'; // initial depth. reference point can be arbitrary.
        char y_depth = '!';
        int x_parent = -1; // initial values must be something the Binary Tree doesn't contain.
        int y_parent = -1;
       
        // Create an empty queue for BFS
        std::queue<std::pair<TreeNode*, std::pair<int, char>>> q;

        // enqueue root. 
        // initialise the 'parent' (root has no parent, so -1) and the depth (zero reference '!')
        std::pair<TreeNode*, std::pair<int, char>> p1{root, std::make_pair(-1, '!')};
        q.push(p1);

        while (!q.empty() && (x_missing || y_missing)) {
            TreeNode* node = q.front().first;
            std::pair<int, char> p = q.front().second;
            
            if (x_missing) {
                if (node->val == x) {
                    x_missing = false;
                    x_parent = p.first;
                    x_depth = p.second;
                }
            }
            
            if (y_missing) {
                if (node->val == y) {
                    y_missing = false;
                    y_parent = p.first;
                    y_depth = p.second;
                }
            }

            if (node->left != nullptr) {
                q.push(std::make_pair(node->left, std::make_pair(node->val, p.second + 1)));
            }

            if (node->right != nullptr) {
                q.push(std::make_pair(node->right, std::make_pair(node->val, p.second + 1)));
            }
            
            q.pop();
        }
        
        return (x_parent != y_parent) && (x_depth == y_depth);
    }
};
