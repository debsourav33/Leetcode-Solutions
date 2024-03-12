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

    /*
    Approach: 
    Maintain Prefix Sum. For an index i, find the leftmost index k having same prefix sum (that means sum of elements between i and k is 0)
    Mark this block (k to i) to be removed
    */
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v, keep;
        ListNode* nd = head;
        while(nd!=nullptr){
            v.push_back(nd->val);
            nd = nd->next;
        }

        int n = v.size();
        vector<int> pref(n,0);
        
        //store index of each prefix_sum
        unordered_map<int,int> pref_idx;
        pref_idx[0] = -1; //0 has a idx of -1

        pref[0] = v[0];
        if(pref_idx.count(pref[0]) == 0) pref_idx[pref[0]] = 0;

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + v[i];
            if(pref_idx.count(pref[i]) == 0)  pref_idx[pref[i]] = i; //keep leftmost only
        }

        //traverse from end and find the leftmost boundary -> this ensures widest block of zero sum
        for(int i=n-1;i>=0; ){
            int p = pref[i];
            if(pref_idx[p]==i){
                keep.push_back(i);
                i--;
            }
            else  i = pref_idx[p];
        }
        
        //indices to keep are from end -> reverse them to get order from begining
        reverse(keep.begin(), keep.end());
        
        //adjust the list so that nodes having indices contained in 'keep' is kept only
        if(keep.empty())  return nullptr;
        for(int i=0;i<keep[0];i++)  head=head->next; //special consideration for starting node

        auto last = head;
        for(int i=1;i<keep.size();i++){
            int k = keep[i] - keep[i-1] - 1;

            auto nxt = last->next;
            while(k--){
                nxt = nxt->next;
            }

            last->next = nxt;
            last = nxt;
        }

        last->next = nullptr;
        
        return head;
    }
};
