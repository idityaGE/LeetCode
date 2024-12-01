class Solution {
public:
    vector<int> findBoundary(vector<int>& arr, bool next) {
        int n = arr.size();
        vector<int> boundary(n);
        stack<int> st;

        int start = next ? n - 1 : 0;
        int end = next ? -1 : n;
        int step = next ? -1 : 1;

        for (int i = start; i != end; i += step) {
            while (!st.empty() &&
                   (next ? arr[st.top()] >= arr[i] : arr[st.top()] > arr[i]))
                st.pop();

            boundary[i] = st.empty() ? (next ? n : -1) : st.top();
            st.push(i);
        }

        return boundary;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findBoundary(heights, true);
        vector<int> pse = findBoundary(heights, false);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    vector<vector<int>> prefixSum(vector<vector<char>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> psum(row, vector<int>(col, 0));

        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                if (mat[j][i] == '1')
                    psum[j][i] = (j == 0) ? 1 : psum[j - 1][i] + 1;
                else
                    psum[j][i] = 0;
            }
        }

        return psum;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty() || mat[0].empty())
            return 0;

        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> psum = prefixSum(mat);

        int maxArea = 0;

        for (int i = 0; i < row; i++) {
            int area = largestRectangleArea(psum[i]);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
