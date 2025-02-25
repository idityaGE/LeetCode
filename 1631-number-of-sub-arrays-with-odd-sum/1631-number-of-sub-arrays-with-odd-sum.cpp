class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long cnt = 0;
        if (n == 1)
            return (arr[0] & 1) == 0 ? 0 : 1;
        
        // for (int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum += arr[j];
        //         if (sum & 1 == 1)
        //             cnt++;
        //     }
        // }

        long long prefixSum = 0;
        for(auto n : arr) {
            prefixSum += n;
            cnt += prefixSum & 1;
        }
        cnt += (n - cnt) * cnt;
        return cnt % 1'000'000'007;
    }
};