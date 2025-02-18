class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return NULL;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* slow = ans;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;

        return ans->next;
    }
};


Input: [1,3,4,7,1,2,6]
  Output: [1,3,4,1,2,6]
