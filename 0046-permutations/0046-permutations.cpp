class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> curr;

        backtrack(nums, used, curr, ans);

        return ans;
    }

    void backtrack(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& curr,
                   vector<vector<int>>& ans) {

        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                curr.push_back(nums[i]);

                backtrack(nums, used, curr, ans);

                curr.pop_back();
                used[i] = false;
            }
        }
    }
};