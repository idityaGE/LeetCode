class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res = "1";
        for (int i = 2; i <= n; i++) {
            res = RLE(res);
        }
        return res;
    }

    string RLE(const string& s) {
        string res = "";
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                res += to_string(count) + s[i - 1];
                count = 1;
            }
        }
        res += to_string(count) + s.back();
        return res;
    }
};
