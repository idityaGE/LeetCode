class Solution {
public:
    bool checkPowersOfThree(int n) {
        /*
            91 => 1 0 1 0 1 -> true
            46 => 1 2 0 1 -> false
        */

        while(n > 0) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};