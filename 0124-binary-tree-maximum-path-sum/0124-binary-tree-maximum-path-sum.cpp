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
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int maxPath = root->val;
        dfs(root, &maxPath);

        return maxPath;
    }

    int dfs(TreeNode* node, int* maxPath) {
        if (node == nullptr)
            return 0;
        int l = max(0, dfs(node->left, maxPath));
        int r = max(0, dfs(node->right, maxPath));
        int currPath = node->val + l + r;
        *maxPath = max(*maxPath, currPath);
        return max(l, r) + node->val;
    }
};