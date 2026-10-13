class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        for (int x: nums) sq.push_back(1LL * x * x);
        sort(sq.begin(), sq.end());
        long long total = accumulate(sq.begin(), sq.end(), 0LL);
        long long small = accumulate(sq.begin(), sq.begin() + sq.size() / 2, 0LL);
        return total - 2 * small;
    }
};