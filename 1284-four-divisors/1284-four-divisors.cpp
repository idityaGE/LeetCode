class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long sum = 0;
        for (auto num : nums) {
            int temp = ff(num);
            sum += temp;
            if (sum > INT_MAX)
                return INT_MAX;
        }

        return int(sum);
    }

    int ff(int num) {
        int cnt = 1;
        int sum = 1;
        for (int i = 2; i <= num; i++) {
            if (num % i == 0) {
                cnt++;
                sum += i;
            }

            if (cnt > 4)
                return 0;
        }

        if (cnt == 4)
            return sum;

        return 0;
    }
};