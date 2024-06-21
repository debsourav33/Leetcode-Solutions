/*
TC: O(n)
SC: O(1)

Sliding Window
*/
class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& grumpy, int m) {
        int n = c.size();
        int ans = 0;

        //first add all non-grumpy ones
        //plus add grumpy ones in first m minutes (utilization of the power)
        for(int i=0;i<n;i++)
            if(i<m || !grumpy[i])  ans +=  c[i]; 

        int best = ans;

        //slide the window of the grumpy power
        for(int i=m;i<n;i++){
            if(grumpy[i-m])
                ans -= c[i-m];
            
            if(grumpy[i])
                ans += c[i];

            best = max(ans, best);
        }

        return best;
    }
};
