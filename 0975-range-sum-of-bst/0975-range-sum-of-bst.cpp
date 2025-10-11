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
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }

    int solve(TreeNode* node, int low, int high) {
        if (!node)
            return 0;

        if (node->val >= low && node->val <= high)
            return node->val + solve(node->left, low, high) +
                   solve(node->right, low, high);

        if (node->val < low)
            return solve(node->right, low, high);

        return solve(node->left, low, high);
    }
};