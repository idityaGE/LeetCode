class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int cnt = 1;
        for (auto num: nums) {
            if (n % cnt == 0) sum += (num * num);
            cnt++;
        }
        
        return sum;
    }
};