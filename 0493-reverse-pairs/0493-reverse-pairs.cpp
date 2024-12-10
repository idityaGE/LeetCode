class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }
        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    int countPair(vector<int>& arr, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            // Use long long to avoid overflow
            while (right <= high && (long long)arr[i] > 2LL * arr[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int merge_sort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += merge_sort(arr, low, mid);
        cnt += merge_sort(arr, mid + 1, high);
        cnt += countPair(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(nums, 0, n - 1);
    }
};