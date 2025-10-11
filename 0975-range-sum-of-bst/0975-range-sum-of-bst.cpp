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
    int low;
    int high;
    int rangeSumBST(TreeNode* root, int _low, int _high) {
        low = _low;
        high = _high;
        int sum = 0;
        solve(root, &sum);
        return sum;
    }

    void solve(TreeNode* node, int *sum) {
        if (node == NULL)
            return;

        if (node->val <= high && node->val >= low)
            *sum += node->val;

        solve(node->left, sum);
        solve(node->right, sum);
    }
};