class Solution {
public:
    int goal(vector <int> &nums, int goal) {
        if (goal < 0) return 0;
        int sum = 0, cnt = 0, l = 0;
        for(int r =0; r < nums.size(); r++) {
            sum += nums[r] % 2;
            while(sum > goal) 
                sum -= nums[l++] % 2;
            cnt += r-l+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return goal(nums, k) - goal(nums, k -1 );
    }
};