class Solution {
public:
    bool isNum(char ch) { return (ch >= '0') && (ch <= '9'); }

    string clearDigits(string s) {
        stack<char> st;
        string res = "";

        for (const char& ch : s) {
            if (isNum(ch)) {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(ch);
            }
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
