class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(1, "(", ans, n);
        return ans;
    }

    void backtrack(int len, string str, vector<string>& ans, int n) {
        if (len == 2 * n) {
            if (valid(str)) {
                ans.push_back(str);
            }
            return;
        }

        char choices[2] = { '(', ')' };
        for (auto ch : choices) {
            str += ch;
            backtrack(len + 1, str, ans, n);
            if (!str.empty()) {
                str.pop_back();
            }
        }
    }

    bool valid(string str) {
        stack<char> stack;
        for (auto ch: str ) {
            if (ch == '(') stack.push(ch);
            else {
                if (stack.empty()) {
                    return false;
                } else {
                    stack.pop();
                }
            }
        }
        return stack.empty() ? true : false;
    }
};