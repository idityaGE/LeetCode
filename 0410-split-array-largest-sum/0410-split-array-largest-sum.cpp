class Solution {
public:
    bool isSplitPossible(vector<int> arr, int k, int maxTime) {
        int sumTime = arr[0];
        int painters = 1;
        for (int i = 1; i < arr.size(); i++) {
            sumTime += arr[i];
            if (sumTime > maxTime) {
                painters++;
                sumTime = arr[i];
            }
        }
        return painters <= k;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n)
            return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isSplitPossible(arr, k, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};