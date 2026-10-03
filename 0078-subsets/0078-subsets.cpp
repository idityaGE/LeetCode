class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(0,curr, nums, ans);

        return ans;
    }

    void backtrack(int start, vector<int> curr, vector<int> nums, vector<vector<int>> &ans) {
        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i+1, curr, nums, ans);
            curr.pop_back();
        }
    }
};