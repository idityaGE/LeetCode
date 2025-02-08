class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] > 5)
            return false;
        int five = 0, ten = 0;

        for (const auto& b : bills) {
            if (b == 5)
                five++;
            else if (b == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else
                    return false;
            } else {
                if (five > 0 && ten > 0)
                    five--,ten--;
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};