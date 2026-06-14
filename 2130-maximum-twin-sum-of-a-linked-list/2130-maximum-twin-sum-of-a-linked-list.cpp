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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        if (!head)
            return 0;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* revList = reverseList(slow);

        int twinSum = 0;
        while (revList) {
            twinSum = max(twinSum, (head->val + revList->val));
            
            head = head->next;
            revList = revList->next;
        }

        return twinSum;
    }
};