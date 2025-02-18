class Solution {
public:

    void reverse( ListNode*& root,ListNode*curr,ListNode *pre){
         if (!curr) return;
        if (!curr->next) {
            curr->next = pre;
            root = curr;
            return;
        }
        ListNode* next = curr->next;
        curr->next = pre;
        reverse(root, next, curr);
     }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        
        ListNode* leftNode = pre->next;
        ListNode* rightNode = leftNode;
        for (int i = 0; i < right - left; ++i) {
            rightNode = rightNode->next;
        }
        
        ListNode* nextNode = rightNode->next;
        rightNode->next = nullptr;
        
        ListNode* root = nullptr;
        reverse(root, leftNode, nullptr);
        pre->next = root;
        leftNode->next = nextNode;
        
        return dummy.next;
    }

};

Input: [1,2,3,4,5]
  Output: [1,4,3,2,5]
