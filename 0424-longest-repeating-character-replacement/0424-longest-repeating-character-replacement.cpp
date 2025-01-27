class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int maxlen = 0;
        int maxFreq = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            if ((r - l + 1) - maxFreq > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }
        
        return maxlen;
    }
};
