class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 1)
            return 0;

        sort(nums.begin(), nums.end());

        int i = 0;
        int maxLen = 0;

        for (int j = 1; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k)
                i++;

            maxLen = max(maxLen, j - i + 1);
        }

        return n - maxLen;
    }
};