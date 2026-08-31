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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        int position = 0;
        while (curr != NULL && curr->next != NULL) {
            if (prev != NULL && curr->next != NULL) {
                if ((curr->val > prev->val && curr->val > curr->next->val) ||
                    (curr->val < prev->val && curr->val < curr->next->val)) {
                    criticalPoints.push_back(position);
                }
            }

            prev = curr;
            curr = curr->next;
            position++;
        }

        if (criticalPoints.size() < 2)
            return {-1, -1};

        if (criticalPoints.size() < 2)
            return {-1, -1};
        
        int maxDist = criticalPoints.back() - criticalPoints.front();
        int minDist = INT_MAX;

        for (int i = 0; i < criticalPoints.size() - 1; i++)
            minDist = min(minDist, criticalPoints[i + 1] - criticalPoints[i]);

        return {minDist, maxDist};
    }
};