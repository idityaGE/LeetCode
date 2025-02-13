class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> 
                    pq(nums.begin(), nums.end());
        int cnt = 0;
        while(!(pq.top() >= k)) {
            long long num1 = pq.top(); pq.pop();
            long long num2 = pq.top(); pq.pop();
            long long newNum = (long long)(num1 * 2) + num2;
            pq.emplace(newNum);
            cnt++;
        }
        return cnt;
    }
};