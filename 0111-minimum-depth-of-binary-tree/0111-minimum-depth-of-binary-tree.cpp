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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        queue<pair<TreeNode*, int>> q;

        q.push({root, 1});

        while (!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();

            if (!temp.first->left && !temp.first->right) 
                return temp.second;
            

            if (temp.first->left) 
                q.push({temp.first->left, temp.second + 1});
            
            if (temp.first->right) 
                q.push({temp.first->right, temp.second + 1});
        
        }

        return 0;
    }
};