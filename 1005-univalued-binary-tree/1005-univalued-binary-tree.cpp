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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return verify(root->left, val) && verify(root->right, val);
    }

    bool verify(TreeNode* node, int val) {
        if (!node) return true;
        if (node->val != val) {
            return false;
        }
        bool v1 = verify(node->right, val);
        bool v2 = verify(node->left, val);
        return v1 && v2;
    }
};