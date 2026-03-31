/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev, *curr, *next;
    prev = NULL;
    curr = head;
    next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    head = reverseList(head);
    struct ListNode* temp = head;
    if (n - 1 == 0) {
        if (temp->next != NULL) {
            head = head->next;
            head = reverseList(head);
            return head;
        } else {
            return NULL;
        }
    }
    while (temp != NULL && n--) {
        if (n - 1 == 0)
            temp->next = temp->next->next;
        else {
            temp = temp->next;
        }
    }
    head = reverseList(head);
    return head;
}