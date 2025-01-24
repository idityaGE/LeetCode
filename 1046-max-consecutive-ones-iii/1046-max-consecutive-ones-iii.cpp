class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int cntZero = 0;
        int l = 0, r = 0;

        while (r < nums.size()) {
            if (nums[r] == 0)
                cntZero++;

            while (cntZero > k)
                if (nums[l++] == 0)
                    cntZero--;

            if (cntZero <= k)
                maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};