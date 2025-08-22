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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {  // Found node to delete
            // If no left child, return right child (handles 0 or 1 child cases)
            if (!root->left) return root->right;
            
            // If no right child, return left child
            if (!root->right) return root->left;
            
            // Both children exist - find predecessor in left subtree
            TreeNode* prev = root->left;
            while (prev->right) prev = prev->right;
            
            // Replace value and delete predecessor
            root->val = prev->val;
            root->left = deleteNode(root->left, prev->val);
        }
        return root;
    }
};