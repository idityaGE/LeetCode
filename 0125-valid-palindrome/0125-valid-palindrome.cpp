class Solution {
public:
    bool ispali(string& s, int i = 0) {
        if (i >= s.size() / 2)
            return true;
        if (s[i] != s[s.size() - i - 1])
            return false;
        return ispali(s, i + 1);
    }
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return ispali(s);
    }
};
