class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int preSum = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            preSum += arr[i];
            int rem = preSum - k;
            cnt += mp[rem];
            mp[preSum]++;
        }

        return cnt;
    }
};