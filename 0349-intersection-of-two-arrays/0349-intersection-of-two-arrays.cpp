class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        
        for(auto i: nums1)
            mp[i]++;
        
        for(auto j: nums2) {
            if(mp.find(j) != mp.end()) {
                res.push_back(j);
                mp.erase(j);
            }
        }

        return res;
    }
};