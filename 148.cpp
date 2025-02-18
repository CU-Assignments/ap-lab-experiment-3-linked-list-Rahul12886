class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        sort(arr.begin(), arr.end());
        
        temp = head;
        for(int i = 0; temp != nullptr; i++){
            temp->val = arr[i];
            temp = temp->next;
        }     
        return head; 
       
    }
};

Input: [4,2,1,3]
  Output: [1,2,3,4]
