class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        vector<int> bits;
        solve(bits, root, sum);
        return sum;
    }

    void solve(vector<int>& bits, TreeNode* node, int& sum) {
        if (!node) return;

        bits.push_back(node->val);

        // If leaf node â convert and add
        if (!node->left && !node->right) {
            sum += convert(bits);
        } else {
            solve(bits, node->left, sum);
            solve(bits, node->right, sum);
        }

        bits.pop_back();  // backtrack properly
    }

    int convert(vector<int>& arr) {
        int num = 0;
        for (int bit : arr) {
            num = (num << 1) | bit;   // shift left + add bit
        }
        return num;
    }
};