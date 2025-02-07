class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> keyToValue;
        unordered_map<int, int> valueCount;
        vector<int> result;
        int distinctValues = 0;

        for (const auto& q : queries) {
            int key = q[0], value = q[1];
            
            if (keyToValue.count(key)) {
                int oldValue = keyToValue[key];
                if (--valueCount[oldValue] == 0) {
                    distinctValues--;
                }
            }

            keyToValue[key] = value;
            if (++valueCount[value] == 1) {
                distinctValues++;
            }

            result.push_back(distinctValues);
        }

        return result;
    }
};