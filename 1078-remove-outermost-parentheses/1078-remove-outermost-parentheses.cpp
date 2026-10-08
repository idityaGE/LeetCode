class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        st.push(s[0]);
        int last = 0;

        string ans = "";

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '(') st.push(s[i]);
            else {
               st.pop();
               if (st.empty()) {
                ans += s.substr(last+1, i - last - 1);
                last = i+1;
               }
            }
        }

        return ans;
    }
};