class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        current = (current << 1) | node->val;

        if (!node->left && !node->right)
            return current;

        return dfs(node->left, current) +
               dfs(node->right, current);
    }
};