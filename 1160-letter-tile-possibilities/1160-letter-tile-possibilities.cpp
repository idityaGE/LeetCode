class Solution {
public:
    int numTilePossibilities(string tiles) {
        int charCount[26] = {0};
        for (char ch : tiles)
            charCount[ch - 'A']++;
        return findSeq(charCount);
    }

private:
    int findSeq(int charCount[26]) {
        int totalCount = 0;

        for (int pos = 0; pos < 26; pos++) {
            if (charCount[pos] == 0)
                continue;

            totalCount++;
            charCount[pos]--;
            totalCount += findSeq(charCount);
            charCount[pos]++;
        }

        return totalCount;
    }
};