class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;

        for(auto a: asteroids) {
            if(a > 0)
                st.push(a);
            else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(a)) 
                    st.pop();

                if (st.empty() || st.top() < 0)
                    st.push(a); 

                if (!st.empty() && st.top() == abs(a))
                    st.pop();
            }
        }

        vector<int> ans(st.size());
        int i = st.size() - 1;
        
        while(!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }

        return ans;
    }
};