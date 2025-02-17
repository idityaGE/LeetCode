class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> seq;
        vector<bool> used(tiles.length(), false);

        generateSeq(tiles, "", used, seq);

        return seq.size() - 1;
    }

private:
    void generateSeq(string& tiles, string current, vector<bool>& used,
                     unordered_set<string>& seq) {
        seq.insert(current);
        for (int pos = 0; pos < tiles.length(); ++pos) {
            if (!used[pos]) {
                used[pos] = true;
                generateSeq(tiles, current + tiles[pos], used, seq);
                used[pos] = false;
            }
        }
    }
};