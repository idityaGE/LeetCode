/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        postorder(root, p, q, ans);
        return ans;
    }

    pair<bool, bool> postorder(TreeNode* root, TreeNode* p, TreeNode* q,
                               TreeNode*& ans) {
        if (!root)
            return {0, 0};
        pair<bool, bool> left = postorder(root->left, p, q, ans);
        pair<bool, bool> right = postorder(root->right, p, q, ans);

        pair<bool, bool> curr = {left.first || right.first,
                                 left.second || right.second};

        if (root == p)
            curr.first = true;
        if (root == q)
            curr.second = true;

        if (curr.first && curr.second && ans == nullptr)
            ans = root;

        return curr;
    }
};