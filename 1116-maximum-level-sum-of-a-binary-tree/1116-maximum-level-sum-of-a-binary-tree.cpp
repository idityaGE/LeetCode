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
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        vector<int> l;

        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            l.push_back(sum);
        }

        int largest = l[0];
        int ans = 0;
        for (int i = 1; i < l.size(); i++) {
            if (l[i] > largest) {
                largest = l[i];
                ans = i;
            }
        }

        return ans + 1;
    }
};