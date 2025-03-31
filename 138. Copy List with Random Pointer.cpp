/*
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)  return head;
        
        // create a copy of each node and link it after the original node
        auto curr = head;
        while(curr){
            auto nxt = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nxt;

            curr = nxt;
        }

        // for a original node, the next node is the copy node
        // so the original node's random pointed node's next = copied node's random pointed node
        curr = head;
        while(curr && curr->next){
            if(!curr->random)  curr->next->random = nullptr;
            else  curr->next->random = curr->random->next;
            
            curr = curr->next->next;
        }

        //extract new && restore original list
        auto orig = head;
        auto ret = head->next;
        curr = head->next;
        while(orig){
            orig->next = orig->next->next;
            orig = orig->next;

            if(curr->next){
                curr->next = curr->next->next;
                curr = curr->next;
            }
        }

        return ret;
    }
};
