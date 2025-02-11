class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];

        string result = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char current = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
                if (i >= strs[j].length() || strs[j][i] != current)
                    return result;
            result += current;
        }
        
        return result;
    }
};