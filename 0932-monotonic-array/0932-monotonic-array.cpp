class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int inc = 0, dec = 0;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] <= nums[i+1]) inc++;
            if(nums[i] >= nums[i+1]) dec++;
        }

        if (inc == nums.size() - 1 || dec == nums.size() - 1)
            return true;
            
        return false;  
    }
};