class Solution {
public:
    void combinations(int index, int target, vector<int>& arr,
                      vector<vector<int>>& res, vector<int>& subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        
        if (index >= arr.size() || target < 0)
            return;
            
        for (int i = index; i < arr.size(); i++) {
            // Skip duplicates
            if (i > index && arr[i] == arr[i-1]) 
                continue;
                
            subset.push_back(arr[i]);
            combinations(i + 1, target - arr[i], arr, res, subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> res;
        vector<int> subset;
        combinations(0, target, arr, res, subset); // Changed hardcoded 8 to target
        
        return res;
    }
};