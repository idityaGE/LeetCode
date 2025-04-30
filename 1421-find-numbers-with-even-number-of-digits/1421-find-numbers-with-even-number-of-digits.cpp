class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto &num : nums) {
            int cnt = 0;
            int n = num;
            while(n != 0) {
                n /= 10;
                cnt++;
            }
            if (cnt % 2 == 0) res++;
        }
        return res;
    }
};