class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using P = pair<int, int>;
        priority_queue<P> pq;
        for (int i = 0; i < points.size(); i++) {
            int dis = distance(points[i]);
            pq.push({dis, i});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        } 
        return ans;
    }

    int distance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};