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
    unordered_map<int, int> mp;
    vector<int> findMode(TreeNode* root) {
        inOrder(root);

        int maxFreq = INT_MIN;
        for (auto& it : mp) {
            if (it.second > maxFreq)
                maxFreq = it.second;
        }

        vector<int> ans;
        for (auto& it : mp) {
            if (it.second == maxFreq)
                ans.push_back(it.first);
        }

        return ans;
    }

    void inOrder(TreeNode* node) {
        if (!node)
            return;

        inOrder(node->left);

        mp[node->val]++;

        inOrder(node->right);
    }
};