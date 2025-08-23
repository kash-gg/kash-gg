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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
inorder(root, arr);
return arr[k-1];  // k-1 because array is 0-indexed
    }
    void inorder(TreeNode* root, vector<int>& arr) {
    if (!root) return;
    
    inorder(root->left, arr);   // Visit left subtree
    arr.push_back(root->val);   // Process current node
    inorder(root->right, arr);  // Visit right subtree
}

};