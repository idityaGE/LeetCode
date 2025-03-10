class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        long long cnt = 0;
        int start = 0, end = 0;
        int consCnt = 0;
        unordered_map<char, int> vowCnt;

        vector<int> nextCons(n);
        int nextConsIdx = n;
        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = nextConsIdx;
            if (!isVowel(word[i]))
                nextConsIdx = i;
        }

        while (end < n) {
            char ch = word[end];

            if (isVowel(ch))
                vowCnt[ch]++;
            else
                consCnt++;

            while (consCnt > k) {
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    vowCnt[startLetter]--;
                    if (vowCnt[startLetter] == 0)
                        vowCnt.erase(startLetter);
                } else
                    consCnt--;
                start++;
            }

            while (start < n && vowCnt.size() == 5 && consCnt == k) {
                cnt += nextCons[end] - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    vowCnt[startLetter]--;
                    if (vowCnt[startLetter] == 0)
                        vowCnt.erase(startLetter);
                } else
                    consCnt--;
                start++;
            }
            end++;
        }
        return cnt;
    }
};