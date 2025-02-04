class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int maxSum = nums[0];
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i])
                sum = 0;
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};