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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> mpp;
        for (auto& num : nums)
            mpp[num] = true;

        ListNode* node = head;
        while (mpp[node->val]) {
            node = node->next;
            head = node;
        }

        while (node->next != nullptr) {
            ListNode* temp = node->next;
            if (mpp[temp->val])
                node->next = temp->next;
            else
                node = node->next;
        }

        return head;
    }
};