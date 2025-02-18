class Solution {
public:
    pair<int, int> findSmallest(vector<int>& arr) {
        int n = arr.size();
        pair<int, int> ans = {INT_MAX, INT_MAX};

        for (int& n : arr) {
            if (n <= ans.first) {
                ans.second = ans.first;
                ans.first = n;
            } else if (n > ans.first && n < ans.second)
                ans.second = n;
        }
        return ans;
    }
    int buyChoco(vector<int>& prices, int money) {
        pair<int, int> smallest = findSmallest(prices);
        int twoChocoPrice = smallest.first + smallest.second;

        if (smallest.second == INT_MAX)
            return money;

        return (twoChocoPrice > money) ? money : money - twoChocoPrice;
    }
};