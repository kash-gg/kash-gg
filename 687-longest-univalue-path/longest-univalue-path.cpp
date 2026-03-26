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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);

        return ans;
    }
    int dfs(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;

        int leftPath = 0;
        int rightPath = 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        if (root->left) {
            if (root->val == root->left->val) {
                leftPath = left + 1;
            }
        }
        if (root->right) {
            if (root->val == root->right->val) {
                rightPath = right + 1;
            }
        }
        ans = max(ans, leftPath + rightPath);
        return max(leftPath, rightPath);
    }
};