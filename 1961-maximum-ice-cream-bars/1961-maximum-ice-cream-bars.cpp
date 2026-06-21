class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // find the maxCost
        int maxCost = INT_MIN;
        for (auto &it: costs)
            if (it > maxCost) 
                maxCost = it;

        vector<int> count(maxCost+1, 0);
        for (auto &it: costs) 
            count[it]++;

        int bars = 0;
        for (int cost = 1; cost <= maxCost; cost++) {
            if (count[cost] > 0) {
                int canbuy = min(count[cost], coins / cost);
                bars += canbuy;
                coins -= canbuy * cost;

                if (coins == 0) return bars;
            }
        }

        return bars;
    }
};