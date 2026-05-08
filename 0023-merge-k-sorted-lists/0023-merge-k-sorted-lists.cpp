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
        if (lists.size() == 0)
            return NULL;

        ListNode* head = NULL;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* tmph = lists[i];
            if (!tmph)
                continue;
            while (tmph) {
                pq.push(tmph->val);
                tmph = tmph->next;
            }
        }

        if (!pq.size())
            return head;

        head = new ListNode(pq.top());
        ListNode* tail = head;
        pq.pop();
        while (pq.size()) {
            tail->next = new ListNode(pq.top());
            pq.pop();
            tail = tail->next;
        }

        return head;
    }
};