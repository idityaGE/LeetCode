class Solution {
public:
    string removeOccurrences(string s, string part) {
        if (s.empty() || part.empty()) return s;
        
        const int m = part.length();
        string result;
        result.reserve(s.length());
        
        int i = 0;
        while (i < s.length()) {
            result.push_back(s[i]);
            
            if (result.length() >= m) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (result[result.length() - m + j] != part[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    result.resize(result.length() - m);
                }
            }
            i++;
        }
        
        return result;
    }
};