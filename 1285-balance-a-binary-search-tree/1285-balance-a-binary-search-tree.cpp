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
    void inorder(TreeNode* node, vector<int>& arr) {
        if (!node)
            return;
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return build(0, arr.size() - 1, arr);
    }

    TreeNode* build(int l, int r, vector<int>& arr) {
        if (l > r)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = build(l, mid - 1, arr);
        node->right = build(mid + 1, r, arr);

        return node;
    }
};