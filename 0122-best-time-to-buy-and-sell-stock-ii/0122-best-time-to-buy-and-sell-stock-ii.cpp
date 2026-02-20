class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;

        int totalProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;

            if (profit > 0) {
                totalProfit += profit;
                minPrice = prices[i];        
            }
        }

        return totalProfit;
    }
};