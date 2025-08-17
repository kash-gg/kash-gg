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
    bool findTarget(TreeNode* root, int k) {
        std::unordered_set<int> s;
        return dfs(root, k, s);
    }
    bool dfs(TreeNode* node,int k,std::unordered_set<int>& s){
        if(!node) return false;
        if(s.count(k-node->val)) return true;
        s.insert(node->val);
        return dfs(node->left,k,s) || dfs(node->right,k,s);
    }
};