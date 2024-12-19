class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        int n = res.size();
        int carry = 1;

        for(int i = n - 1; i >= 0 && carry; --i) {
            res[i] += carry;
            if(res[i] == 10) {
                res[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if (carry) res.insert(res.begin(), 1);

        return res;
    }
};