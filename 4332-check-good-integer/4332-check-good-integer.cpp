class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0, squareSum = 0;
        while (n > 0) {
            int rem = n % 10;
            n /= 10;
            digitSum += rem;
            squareSum += (rem * rem);
        }

        return squareSum - digitSum >=  50;
    }
};