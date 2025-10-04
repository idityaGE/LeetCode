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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        check(root, &maxDia);
        return maxDia;
    }

    int check(TreeNode* node, int *maxDia) {
        if (node == nullptr) return 0;

        int lh = check(node->left, maxDia);
        int rh = check(node->right, maxDia);

        *maxDia = max(*maxDia, lh + rh);

        return max(lh, rh) + 1;
    }  
};