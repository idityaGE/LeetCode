class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> idx;
        int i = 0;
        for (auto& str : words) {
            for (auto& chr : str) {
                if (chr == x) {
                    idx.push_back(i);
                    break;
                }
            }
            i++;
        }

        return idx;
    }
};