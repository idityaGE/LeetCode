class Solution {
public:
    bool canStealKHouses(vector<int>& nums, int k, int mid) {
        int cnt = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= mid) {
                cnt++;
                i += 2;
            } else
                i++;
        }
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canStealKHouses(nums, k, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};