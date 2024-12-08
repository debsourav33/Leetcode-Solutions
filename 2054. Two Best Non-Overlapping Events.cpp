/*
Time: O(nlogn)
Space: O(1)

Binary search:
    Find length of ascendingly increasing prefix and suffix
    Minimum of them subtracted from total is the inital answer
     
    Then for every index i in that ascending suffix, find the largest index k from ascending prefix such that a[i] >= a[k] with binary search. The gap between them is to be removed.

    Update answer with the minimum gap to be removed.
*/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        
        int l = 0, r = n-1;
        
        //Find length of ascendingly increasing prefix and suffix
        while(l<n-1 && a[l+1] >= a[l])  l++;
        while(r>0 && a[r] >= a[r-1])  r--;

        int ans = min(n-1-l, r); //min of prefix to remove and suffix to remove

        //Then for every index i in that ascending suffix, find the largest index k from ascending prefix such that a[i] >= a[k] with binary search. The gap between them is to be removed.
        for(int i=n-1;i>l;i--){
            int lo = 0, hi = l;

            while(lo<hi){
                int mid = (lo+hi+1)/2;

                if(a[mid] <= a[i])  lo = mid;
                else  hi = mid-1;  
            }

            //must check if a[i] >= a[lo]
            if(a[lo] <= a[i])  ans = min(ans, i-lo-1);

            
            if(a[i-1] > a[i])  break; //ascending order broken for suffix, we stop
        }

        return ans;
    }
};/*
Time: O(nlogn)
Space: O(n)

- Sort using start time
- Maintain min-heap on end time
- For an interval e, pop the heap until the end time overlaps with e's start time
- Track maximum of the popped intervals' value and add with the current interval e's value to get maximum gain for the current interval
- The best maximum gain across all intervals is the answer

*/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& ev) {
        auto cmp = [](vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        };

        sort(ev.begin(), ev.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        int maxi = 0, ans = 0;

        for(auto &e: ev){
            while(!pq.empty() && pq.top()[1] < e[0]){
                maxi = max(maxi, pq.top()[2]);
                pq.pop();
            }

            ans = max(ans, maxi+e[2]);
            pq.push(e);
        }

        return ans;

    }
};
