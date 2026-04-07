class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodes;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                nodes.push_back(curr);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (level % 2 == 1) {
                int l = 0, r = nodes.size() - 1;
                while (l < r) {
                    swap(nodes[l]->val, nodes[r]->val);
                    l++;
                    r--;
                }
            }

            level++;
        }

        return root;
    }
};