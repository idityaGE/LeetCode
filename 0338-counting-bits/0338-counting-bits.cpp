class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = count(i);
            ans[i] = cnt;
        }

        return ans;
    }

    int count(int n) {
        int cnt = 0;
        while (n > 0) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};