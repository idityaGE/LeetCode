class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        int ans = nums[0];
        while (s <= e) {
            int m = e + (s - e) / 2;
            if(nums[s] <= nums[e]){
                ans = min(ans, nums[s]);
                break;
            }
            if (nums[s] <= nums[m]) {
                ans = min(ans, nums[s]);
                s = m + 1;
            } else {
                ans = min(ans, nums[m]);
                e = m - 1;
            }
        }
        return ans;
    }
};