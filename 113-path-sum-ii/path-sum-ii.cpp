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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currpath ;
        vector<vector<int>> result;
        dfs(root,targetSum,currpath,result);
        return result;
    }
    void dfs(TreeNode* root,int targetSum ,vector<int>& currpath, vector<vector<int>>& result){
        if(root == NULL) return;

        currpath.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(targetSum == root->val){
                result.push_back(currpath);
            }
        }
        dfs(root -> left,targetSum - root->val,currpath,result);
        dfs(root -> right,targetSum - root->val,currpath,result);
        currpath.pop_back();
    }
};