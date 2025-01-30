class Solution {
public:
    int atmost(vector<int> &nums, int k) {
        if (k < 0) return 0;
        int l = 0;
        int cnt = 0;
        map<int, int> mp;

        for(int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;

            while(mp.size() > k && l <= r) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) 
                    mp.erase(nums[l]);
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};