/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* current = dummy;

        inorder(root, current);

        return dummy->right;
    }
    void inorder(TreeNode* root, TreeNode*& current) {
        if (!root)
            return;
        inorder(root->left, current);
        current->right = new TreeNode(root->val);
        current = current->right;
        inorder(root->right, current);
    }
};