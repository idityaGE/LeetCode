class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int count = 0;
        
        for (auto &it: costs) {
            if (it <= coins) {
                coins -= it;
                count++;
            }
        }

        return count;
    }
};