class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxSum = -1;

        for (int i = 0; i < nums.size(); i++) {
            int digiSum = digitSum(nums[i]);
            if (mp.count(digiSum)) {
                maxSum = max(maxSum, mp[digiSum] + nums[i]);
                if (mp[digiSum] < nums[i])
                    mp[digiSum] = nums[i];
            } else mp[digiSum] = nums[i];
        }

        return maxSum;
    }
};