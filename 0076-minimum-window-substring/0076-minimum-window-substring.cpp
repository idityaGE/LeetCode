class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> hash(128, 0);  
        for (char c : t) hash[c]++; 

        int required = t.length();
        int l = 0, r = 0;
        int minLen = INT_MAX, startIdx = -1;

        while (r < s.length()) {
            if (hash[s[r]] > 0) required--;

            hash[s[r]]--;
            r++; 

            while (required == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    startIdx = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) required++;  
                l++;
            }
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};
