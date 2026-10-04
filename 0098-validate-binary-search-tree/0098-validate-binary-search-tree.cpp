class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

    bool validate(TreeNode* node, long long lower, long long upper) {
        if (!node)
            return true;

        if (node->val <= lower || node->val >= upper)
            return false;

        return validate(node->left, lower, node->val) &&
               validate(node->right, node->val, upper);
    }
};