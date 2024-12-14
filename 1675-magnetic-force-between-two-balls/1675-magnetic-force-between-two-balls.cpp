class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid) {
        int lastBasket = position[0];
        int balls = 1;
        for (int i = 1; i < position.size(); i++) {
            int dist = position[i] - lastBasket;
            if (dist >= mid) {
                balls++;
                lastBasket = position[i];
            }
        }
        return balls >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1;
        int high = position[n - 1] - position[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(position, m, mid)) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return high;
    }
};