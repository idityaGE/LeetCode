class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int p = 0, i = 0;

        while (p < g.size() && i < s.size()) {
            if (g[p] <= s[i])
                p++;
            i++;
        }

        return p;
    }
};
