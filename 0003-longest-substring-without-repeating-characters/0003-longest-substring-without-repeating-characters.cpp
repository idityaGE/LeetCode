class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int> mp;
        int len = 0;
        int maxlen = 0;

        int l = 0, r = 0; 
        while (r < n) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            len = r - l + 1;
            maxlen = max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};
