class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // Greed factors
        sort(s.begin(), s.end());  // Sizes of cookies
        int p = 0;  // Pointer for children
        int cnt = 0;  // Count of content children

        for (int i = 0; i < s.size() && p < g.size(); i++) {
            if (g[p] <= s[i]) {  // If the cookie can satisfy the child
                cnt++;
                p++;  // Move to the next child
            }
        }

        return cnt;
    }
};
