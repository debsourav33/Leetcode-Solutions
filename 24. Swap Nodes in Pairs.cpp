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
    ListNode* swap(ListNode* head){
      if(head==nullptr || head->next==nullptr)  return head;
      //cout<<head->val<<" "<<head->next->val<<endl;
      
      ListNode* tmp = head->next;
      head->next = head->next->next;
      tmp->next = head;      
      
      return tmp;
    }
    
    ListNode* swapPairs(ListNode* head) {
        head = swap(head);
        
        ListNode* curr = head;
        
        while(curr!=nullptr && curr->next!=nullptr){
          curr->next->next = swap(curr->next->next); //important, link between current node and the node returned by the function
          curr = curr->next->next;
        }

        return head;
    }
};
