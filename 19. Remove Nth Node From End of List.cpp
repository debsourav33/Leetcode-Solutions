/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

class Solution{
    public:
    struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
        int cnt = 0;

        if(head->next== nullptr)  return nullptr;

        ListNode *slow = head, *fast = head->next;
        while(fast != nullptr){
            fast = fast->next;
            if(cnt>=n)  slow = slow->next;
            
            cnt++;
        }
        
        if(cnt<n)  head = head->next;
        else  slow->next = slow->next->next;
        
        return head;
    }
};
