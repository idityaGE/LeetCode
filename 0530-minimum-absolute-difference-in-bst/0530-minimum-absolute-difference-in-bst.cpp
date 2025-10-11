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
    int minDiff = INT_MAX;

    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        inOrder(root, prev);
        return minDiff;
    }

    void inOrder(TreeNode* node, TreeNode* &prev) {
        if (!node)
            return;

        inOrder(node->left, prev);

        if (prev)
            minDiff = min(minDiff, node->val - prev->val);

        prev = node;

        inOrder(node->right, prev);
    }
};