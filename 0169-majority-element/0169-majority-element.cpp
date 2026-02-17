class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (auto &num: nums)  mp[num]++;

        for (auto &item: mp) {
            if (item.second > (n >> 1)) return item.first;
        }

        return nums[nums.size() / 2];
    }
};