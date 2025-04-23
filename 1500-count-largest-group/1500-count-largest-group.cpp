class Solution {
public:
    int sumofdigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mpp;
        for (int i = 1; i <= n; i++) 
            mpp[sumofdigits(i)]++;

        int maxSize = 0, count = 0;
        for (auto& [_, val] : mpp) {
            if (val > maxSize) {
                maxSize = val;
                count = 1;
            } else if (val == maxSize) {
                count++;
            }
        }
        return count;
    }
};
