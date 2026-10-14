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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n_list = lists.size();
        vector<vector<int>> l(n_list, vector<int>(0));

        for (int i = 0; i < n_list; i++) {
            ListNode* temp = lists[i];
            while (temp != nullptr) {
                l[i].push_back(temp->val);
                temp = temp->next;
            }
        }

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int i = 0; i < n_list; i++)
            if (!l[i].empty())
                pq.push({l[i][0], i, 0});

        ListNode ans(0);
        ListNode *tail = &ans;

        while (!pq.empty()) {
            auto [value, listIdx, elemIdx] = pq.top();
            pq.pop();

            tail->next = new ListNode(value);
            tail = tail->next;

            if (elemIdx + 1 < l[listIdx].size())
                pq.push({l[listIdx][elemIdx + 1], listIdx, elemIdx + 1});
        }

        return ans.next;
    }
};