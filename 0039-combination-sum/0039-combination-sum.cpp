class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(nums, curr, ans, target , 0, 0);

        return ans;
    }

    void backtrack(vector<int> nums, vector<int> curr, vector<vector<int>> &ans, int target, int sum, int start) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (sum + nums[i] <= target) {
                sum += nums[i];
                curr.push_back(nums[i]);
                backtrack(nums, curr, ans, target, sum, i);
                curr.pop_back();
                sum -= nums[i];
            }
        }
    }
};