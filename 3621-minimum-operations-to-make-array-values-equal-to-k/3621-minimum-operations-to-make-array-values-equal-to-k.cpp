class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i : nums)
            if (i < k)
                return -1;
            else if (i > k)
                mpp[i]++;
        return mpp.size();
    }
};
