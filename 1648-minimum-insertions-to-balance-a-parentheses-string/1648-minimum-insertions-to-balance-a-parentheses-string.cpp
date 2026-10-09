class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') open++;
            else {
                if (i < s.length() - 1 && s[i+1] == ')') i++;
                else ans++;

                if (open > 0) open--;
                else ans++;
            }
        }

        return ans + open * 2;
    }
};