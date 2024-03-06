/*
Time: O(Nlogk)
Space: O(K) (at one moment, atmost k elements can be in the queue)

1. Use priority queue.
2. Push head of all the list.
3. Pick the current minimum node in the queue, pop it and push its next (if not null).
4. Repeat step 3 untill queue is empty

Every node picked will be in the sorted order, so chain them and return the head
*/

class Solution {
public:

    priority_queue<ListNode*, vector<ListNode*>, decltype([](ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    })> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(ListNode* nd: lists){
            if(nd != nullptr)
                q.push(nd);
        }

        if(q.empty())  return nullptr;

        ListNode* ret = q.top();
        q.pop();
        if(ret->next!=nullptr)  q.push(ret->next);

        ListNode* tmp = ret;

        while(!q.empty()){
            ListNode* nd = q.top();
            q.pop();

            tmp->next = nd;
            tmp = tmp->next;

            if(nd->next != nullptr) q.push(nd->next);
        }

        return ret;
    }
};
