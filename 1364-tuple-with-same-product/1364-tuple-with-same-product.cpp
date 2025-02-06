class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        int cnt = 0;

        for (size_t i = 0; i < nums.size(); i++)
            for (size_t j = i + 1; j < nums.size(); j++)
                freq[nums[i] * nums[j]]++;

        for (const auto& a : freq)
            if (a.second > 1)
                cnt += 8 * (a.second * (a.second - 1) / 2);

        return cnt;
    }
};
