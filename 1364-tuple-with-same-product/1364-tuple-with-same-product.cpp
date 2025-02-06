#include <vector>
#include <unordered_map>

class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int cnt = 0;
        
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                freq[nums[i] * nums[j]]++;
            }
        }
        
        for (const auto& a : freq) {
            int n = a.second;
            if (n > 1) {
                cnt += 8 * (n * (n - 1) / 2);
            }
        }

        return cnt;
    }
};
