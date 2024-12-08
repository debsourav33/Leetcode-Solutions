/*
Time: O((n*k)logn))
Space: O(n*k)

DP with Optimized Binary Search

- Sort on the start time
- For each idx i, find the next event attentable (with Binary Search) if even i is attended
- Perform DP, with choose-no choose option, and for each event to choose, find the next event to attend from the precomputed array
*/

class Solution {
public:
    vector<vector<int>> ev, dp;
    int k, n;

    vector<int> next_event;

    int call(int p, int k){
        if(k==0 || p == n)  return 0;
        
        if(dp[p][k] != -1)  return dp[p][k];
        
        //no choose
        int ans = call(p+1, k);
        
        //choose
        //for each event to choose, find the next event to attend from the precomputed array
        int nxt = next_event[p];

        ans = max(ans, ev[p][2] + call(nxt, k-1));
        return dp[p][k] = ans;
    }

    //For each idx i, find the next event attentable (with Binary Search) if even i is attended
    void populate_next_events(){
        for(int p = 0;p<n;p++){
            int lo = p+1, hi = n;

            while(lo<hi){
                int mid = (lo+hi)/2;

                if(ev[mid][0] > ev[p][1])  hi = mid;
                else  lo = mid + 1;
            }

            next_event[p] = lo;
        }
    }

    int maxValue(vector<vector<int>>& ev, int k) {
        sort(ev.begin(), ev.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        this->ev = ev;
        n = ev.size();

        dp = vector(n, vector(k+1, -1));
        next_event = vector(n, n);

        populate_next_events();

        return call(0, k);
    }
};
