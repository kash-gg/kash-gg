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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int a = 0;
        int b = 0;

        TreeNode* l = root;
        TreeNode* r = root;
        
        while(l){
            a++;
            l = l->left;
        }
        while(r){
            b++;
            r= r->right;
        }

        if(a==b){
            return (1<<a)-1;
        }
        return 1 + countNodes(root->left)+ countNodes(root->right);
    }
};