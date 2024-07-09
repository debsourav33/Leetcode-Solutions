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



/*
TC: O(n)
SC: O(1)

Maintain 3 values.. Last-to-last, last, current
Check if last can be a minima
Maintain the first encountered minima and the latest one
Every time you find a minima, check its distance with the latest one to find the minDistance (and then make it the latest minima)

At the end, return maxDistance (distance between first and latest minima) and minDistance

*/
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini = 1e9, maxi = -1, cnt = 2;
        
        int ll = head->val, l = head->next->val;
        head = head->next->next;

        int first = -1, last = -1;

        while(head != nullptr){
            int curr = head->val;
            cnt++;

            if((l > ll && l > curr) || (l < ll && l < curr)){
                //minima found

                //this is not the first minima
                if(last != -1){
                    mini = min(cnt-last, mini);
                    last = cnt;
                }
                else{ //first minima
                    first = last = cnt;
                } 
            }

            ll = l;
            l = curr;
            head = head->next;
        }

        //less than 2 minima found
        if(first == last)  return {-1, -1};

        maxi = last-first;
        return {mini, maxi};

    }
};
