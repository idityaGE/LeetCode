class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCnt = 0;
        int negCnt = 0;

        for (int num: nums) {
            if (num > 0) posCnt++;
            else if (num < 0) negCnt++;
        }

        return posCnt >= negCnt ? posCnt : negCnt;
    }
};