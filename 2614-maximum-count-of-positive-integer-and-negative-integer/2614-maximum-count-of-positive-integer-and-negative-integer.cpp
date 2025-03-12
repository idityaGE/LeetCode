class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCnt = BS(nums, 0);
        int negCnt = nums.size() - BS(nums, 1);

        return posCnt >= negCnt ? posCnt : negCnt;
    }

    int BS(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = nums.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }
};