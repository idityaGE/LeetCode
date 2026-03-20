class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr (n, 0);

        for(int i = 1; i <= n; i++) arr[i - 1] = i;

        int i = 0;

        while(arr.size() > 1) {
            int idx = (i + k - 1) % arr.size();
            arr.erase(arr.begin() + idx);
            i = idx;
        }

        return arr[0];
    }
};