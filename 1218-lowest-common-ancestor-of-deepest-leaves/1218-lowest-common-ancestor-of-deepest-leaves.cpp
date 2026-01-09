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
    int maxDepth = 0;
    TreeNode* ans = nullptr;

    int solve(TreeNode* node, int level) {
        if (!node)
            return 0;

        int lh = solve(node->left, level + 1);
        int rh = solve(node->right, level + 1);

        if (lh == rh && (lh + level) >= maxDepth) {
            ans = node;
            maxDepth = lh + level;
        }

        return 1 + max(lh, rh);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};