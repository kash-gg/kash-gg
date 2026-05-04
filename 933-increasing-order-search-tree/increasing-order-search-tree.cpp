class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            inorder(node->left);

            curr->right = new TreeNode(node->val);
            curr = curr->right;

            inorder(node->right);
        };

        inorder(root);
        return dummy->right;
    }
};