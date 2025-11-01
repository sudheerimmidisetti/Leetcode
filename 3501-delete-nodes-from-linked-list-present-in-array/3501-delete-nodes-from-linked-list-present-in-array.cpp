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
        ListNode* dummy = head;

        vector<int> arr;
        while (dummy) {
            arr.push_back(dummy->val);
            dummy = dummy->next;
        }

        set<int> st(nums.begin(), nums.end());
        
        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;
        for (int val : arr) {
            if (st.find(val) == st.end()) {
                if (!newHead) {
                    newHead = new ListNode(val);
                    newTail = newHead;
                } else {
                    newTail->next = new ListNode(val);
                    newTail = newTail->next;
                }
            }
        }

        return newHead;
    }
};