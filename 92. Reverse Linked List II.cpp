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

    //use stack to store the nodes in reverse order
    //important: store the next node of right (named, follow)
    //this will be added to the next of the reversed portion
    ListNode* rev(ListNode* node, int diff){
      stack<ListNode*> st;

      st.push(node);
      ListNode* follow = node->next;


      for(int i=0;i<diff;i++){
        node = node->next;
        st.push(node);

        follow = node->next;
      }

      ListNode* revHead = st.top();
      ListNode* tmp = revHead;
      st.pop();

      while(!st.empty()){
        tmp->next = st.top();
        st.pop();

        tmp = tmp->next;
        tmp->next = follow;
      }

      return revHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
      
      if(left==1)  return rev(head, right-left);

      ListNode* before = head;

      for(int i=1;i<left-1;i++){
        before = before->next;
      }

      before->next = rev(before->next, right-left);
      return head;
    }
};
