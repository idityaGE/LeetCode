class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0, l = 0, r = 0;
        map<int, int> mp;

        for (r = 0; r < fruits.size(); r++) {
            mp[fruits[r]]++;

            if (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                l++;
            }

            if (mp.size() <= 2)
                maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};