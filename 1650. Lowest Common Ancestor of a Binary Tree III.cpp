/*
Time O(h)
Space O(1)  solution, when one node reaches root, switch it back to the starting position of the other node (and keep moving again to parent of the nodes until they meet)
            //this way, we will bridge the gap q they had initially for the distances from the lca node
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q){

    Node* sp = p;
    Node* sq = q;

    while(p!=q){
        
        if(p==nullptr){
            p = sq;
        
        }
        else{
            p = p->parent;
        }

        if(q==nullptr){
            q = sp;
        
        }
        else{
            q = q->parent;
        }
    }


    return p;
}
};
