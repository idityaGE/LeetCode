class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> freq;
        vector<int> ans(2, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
                if (freq[grid[i][j]] == 2)
                    ans[0] = grid[i][j];
            }
        }

        for (int i = 1; i <= n * n; i++) {
            if(freq.find(i) == freq.end())
                ans[1] = i;
        }

        return ans;
    }
};