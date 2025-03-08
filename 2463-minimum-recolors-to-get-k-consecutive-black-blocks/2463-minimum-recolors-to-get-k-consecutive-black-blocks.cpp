class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0;
        int ans = INT_MAX;

        for (int i = 0; i < blocks.size(); i++) {
            if (i - k >= 0 && blocks[i - k] == 'B') cnt--;
            if (blocks[i] == 'B') cnt++;
            ans = min(ans, k - cnt);
        }

        return ans;
    }
};