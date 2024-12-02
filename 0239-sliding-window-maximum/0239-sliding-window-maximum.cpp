class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque <int> dq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // removing after every k the element in deque
            if (!dq.empty() && dq.front() <= i-k)
                dq.pop_front();

            // maintaining the monotonic stack
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            if( i >= k - 1) // inserting start from k-1 index
                ans.push_back(nums[dq.front()]);

        }

        return ans;
    }
};