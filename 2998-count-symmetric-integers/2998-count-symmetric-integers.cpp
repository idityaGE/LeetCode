class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int num = low; num <= high; num++) {
            string str = to_string(num);
            short len = str.length();

            if (len % 2 == 1)
                continue;

            short half = len / 2;
            int leftSum = 0;
            int rightSum = 0;

            for (int i = 0; i < half; i++) {
                leftSum += str[i] - '0';
                rightSum += str[i + half] - '0';
            }

            if (leftSum == rightSum)
                cnt++;
        }
        return cnt;
    }
};