class Solution {
public:
    void generateHappyStr(int n, string currentStr, vector<string>& happyStr) {
        if (currentStr.size() == n) {
            happyStr.push_back(currentStr);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (currentStr.size() > 0 && currentStr.back() == ch)
                continue;
            generateHappyStr(n, currentStr + ch, happyStr);
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStr;
        generateHappyStr(n, "", happyStr);

        if (happyStr.size() < k)
            return "";

        sort(happyStr.begin(), happyStr.end());

        return happyStr[k - 1];
    }
};