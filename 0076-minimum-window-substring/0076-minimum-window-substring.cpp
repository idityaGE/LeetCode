class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> hash(128, 0);  
        for (char c : t) hash[c]++; 

        int required = t.length();  // Total characters needed
        int l = 0, r = 0;  // Two pointers
        int minLen = INT_MAX, startIdx = -1;

        while (r < s.length()) {
            // If character at r is required, decrease count
            if (hash[s[r]] > 0) required--;

            hash[s[r]]--;  // Reduce frequency in hash
            r++;  // Expand window

            while (required == 0) {  // When all characters are matched
                // Update minimum window
                if (r - l < minLen) {
                    minLen = r - l;
                    startIdx = l;
                }

                hash[s[l]]++;  // Restore character at l
                if (hash[s[l]] > 0) required++;  
                l++; 
            }
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};
