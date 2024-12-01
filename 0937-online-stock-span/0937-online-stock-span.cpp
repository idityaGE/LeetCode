class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx;

    StockSpanner() {
        idx = -1;
        st = stack<pair<int, int>>(); // Initialize a fresh stack
    }

    int next(int price) {
        idx++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans = idx - (st.empty() ? -1 : st.top().second); // Declare ans here

        st.push({price, idx});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
