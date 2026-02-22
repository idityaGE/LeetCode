class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int, int> mp(arr.size());
        int pref = 0;

        for (int i = 0; i < arr.size(); i++) {
            pref ^= arr[i];
            mp[i] = pref;
        }

        for (auto &item: queries) {
            int st = item[0];
            int end = item[1];

            int out = st > 0 ? mp[st - 1] ^ mp[end] : mp[end];

            res.push_back(out);
        }

        return res;
    }
};