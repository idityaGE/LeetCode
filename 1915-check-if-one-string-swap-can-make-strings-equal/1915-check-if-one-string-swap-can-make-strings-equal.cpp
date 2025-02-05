class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();

        if (n != s2.length()) return false;

        int idx1 = -1, idx2 = -1;
        int diff_count = 0;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff_count++;
                if (idx1 == -1) idx1 = i;
                else if (idx2 == -1) idx2 = i;
                else return false; // More than 2 mismatches
            }
        }

        if (diff_count == 0) return true;
        if (diff_count != 2) return false; 
        
        return s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1];
    }
};
