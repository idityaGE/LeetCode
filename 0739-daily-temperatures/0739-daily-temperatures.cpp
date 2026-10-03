class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> results(temps.size());
        stack <int> stack;
        for (int i = 0; i < temps.size(); i++) {
            while (!stack.empty() && temps[stack.top()] < temps[i]) {
                results[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return results;
    }
};