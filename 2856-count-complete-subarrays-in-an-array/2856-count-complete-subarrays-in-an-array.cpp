class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> mpp;
        for (auto& num : nums)
            mpp[num]++;

        int totalDistinctElements = mpp.size();

        mpp.clear();

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                mpp[nums[j]]++;
                if(mpp.size() == totalDistinctElements)
                    cnt++;
            }
            mpp.clear();
        }

        return cnt;
    }
};