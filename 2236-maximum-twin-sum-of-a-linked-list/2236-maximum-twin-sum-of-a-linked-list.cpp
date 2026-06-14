/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        int maxTwin = INT_MIN;
        for (int i = 0; i < n/2; i++) {
            int tmp = nums[i] + nums[n - i - 1];
            maxTwin = max(tmp, maxTwin);
        } 

        return maxTwin;
    }
};