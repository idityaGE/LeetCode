class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int res = 0;
        bool center = false;

        for (string word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (mp[rev] > 0) {
                res += 4;      // 2 words of 2 letters = 4
                mp[rev]--;     // use the reverse pair
            } else 
                mp[word]++;    // store current word
        }

        for (auto& [word, count] : mp) {
            if (word[0] == word[1] && count > 0) {
                center = true;
                break;
            }
        }

        if (center) res += 2;

        return res;
    }
};
