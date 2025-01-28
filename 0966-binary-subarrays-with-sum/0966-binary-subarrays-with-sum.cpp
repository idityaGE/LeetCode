class Solution {
public:
    int fuck(vector<int> &nums, int goal) {
        if(goal < 0 || nums.size() == 0) return 0;

        int cnt = 0;
        int sum = 0;
        int l = 0;

        for(int r=0;r<nums.size();r++) {
            sum += nums[r];

            while(sum > goal) 
                sum -= nums[l++];
            
            cnt += r-l+1;

        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fuck(nums, goal) - fuck(nums, goal-1);
    }
};