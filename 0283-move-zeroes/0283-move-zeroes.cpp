class Solution {
private:
    void swap(int &a, int &b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }

public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int l = -1;

        for (int i = 0; i < n; i++) {
            if (l == -1 && nums[i] == 0) l = i;

            if (nums[i] != 0 && i != 0 && l != -1) 
                swap(nums[i], nums[l++]);
        }
    }
};