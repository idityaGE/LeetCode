class Solution {
public:
    // int findPivot(vector<int>& nums) {
    //     int low = 0, high = nums.size() - 1;

    //     while (low < high) {
    //         int mid = low + (high - low) / 2;
    //         if (nums[mid] > nums[high])
    //             low = mid + 1;
    //         else
    //             high = mid;
    //     }
    //     return low;
    // }

    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[(i + 1) % nums.size()])
                cnt++;
            if (cnt > 1)
                return false;
        }
        return true;
    }
};