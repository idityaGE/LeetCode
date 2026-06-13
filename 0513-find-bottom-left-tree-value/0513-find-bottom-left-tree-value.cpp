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
    int findBottomLeftValue(TreeNode* root) {
        int last = root->val;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();

            if (tmp->right) {
                q.push(tmp->right);
                last = tmp->right->val;
            } 
            
            if (tmp->left) {
                q.push(tmp->left);
                last = tmp->left->val;
            }
            
        }

        return last;
    }
};