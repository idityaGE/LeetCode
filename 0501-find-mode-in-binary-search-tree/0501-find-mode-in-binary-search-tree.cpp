class Solution {
public:
    int currNum = 0;
    int currFreq = 0;
    int maxFreq = INT_MIN;
    vector<int> res;

    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return res;
    }

    void inOrder(TreeNode* node) {
        if (!node)
            return;

        inOrder(node->left);

        if (currNum == node->val) {
            currFreq++;
        } else {
            currNum = node->val;
            currFreq = 1;
        }

        if (currFreq > maxFreq) {
            res.clear();
            maxFreq = currFreq;
            res.push_back(node->val);
        } else if (currFreq == maxFreq) {
            res.push_back(node->val);
        }

        inOrder(node->right);
    }
};