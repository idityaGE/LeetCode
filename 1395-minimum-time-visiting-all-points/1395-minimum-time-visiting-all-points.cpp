class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int steps = 0;
        int n = points.size();

        for (int i = 0; i < n - 1; i++) {
            pair<int, int> p1 = {points[i][0], points[i][1]};
            pair<int, int> p2 = {points[i + 1][0], points[i + 1][1]};

            steps += helper(p1, p2);
        }

        return steps;
    }

    inline int helper(pair<int, int> p1, pair<int, int> p2) {
        int x_diff = abs(p1.first - p2.first);
        int y_diff = abs(p1.second - p2.second);

        return x_diff > y_diff ? x_diff : y_diff;
    }
};