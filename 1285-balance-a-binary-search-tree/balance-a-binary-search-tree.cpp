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
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<TreeNode*> nodes;
        inorder(root, nodes);  // Step 1: Get nodes in sorted order
        return buildBalancedBST(nodes, 0, nodes.size() - 1);  // Step 2: Build balanced BST
    }

private:
    void inorder(TreeNode* root, std::vector<TreeNode*>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);  // Store nodes themselves for reconstruction
        inorder(root->right, nodes);
    }

    TreeNode* buildBalancedBST(const std::vector<TreeNode*>& nodes, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;

        TreeNode* root = nodes[mid];
        // Recursively build the left and right subtrees
        root->left = buildBalancedBST(nodes, left, mid - 1);
        root->right = buildBalancedBST(nodes, mid + 1, right);

        return root;
    }
};
