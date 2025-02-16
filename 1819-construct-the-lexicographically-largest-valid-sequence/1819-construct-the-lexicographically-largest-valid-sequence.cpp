class Solution {
public:
    static inline bool backTrack(int i, vector<int>& ans, vector<bool>& used, int sz, int n) {
        if (sz == i)
            return true;
        if (ans[i] != 0)
            return backTrack(i + 1, ans, used, sz, n);
        [[unroll]]
        for (int num = n; num > 0; num--) {
            if (used[num])
                continue;

            if (num == 1) {
                ans[i] = num;
                used[num] = true;

                if (backTrack(i + 1, ans, used, sz, n))
                    return true;

                ans[i] = 0;
                used[num] = false;
                continue;
            }

            if (i + num >= sz || ans[i + num] != 0)
                continue;

            ans[i] = num;
            ans[i + num] = num;
            used[num] = true;

            if (backTrack(i + 1, ans, used, sz, n))
                return true;

            ans[i] = 0;
            ans[i + num] = 0;
            used[num] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        int sz = 2 * n - 1;
        vector<int> ans(sz, 0);
        vector<bool> used(n + 1, false);

        backTrack(0, ans, used, sz, n);
        return ans;
    }
};
