class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right =
            (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;

        auto canRepairAll =
            [&](long long time) {
                long long totalCarRepaired = 0;
                for (int rank : ranks) {
                    totalCarRepaired += sqrt(time / rank);
                    if (totalCarRepaired >= cars)
                        return true;
                }
                return false;
            };

        while (left < right) {
            long long mid = (left + right) / 2;
            if (canRepairAll(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};