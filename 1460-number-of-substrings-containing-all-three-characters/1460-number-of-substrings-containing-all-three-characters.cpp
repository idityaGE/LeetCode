class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastseen[3] = {-1, -1, -1};
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            lastseen[s[i] - 'a'] = i;

            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});
            }
        }

        return cnt;
    }
};