/*
Time: O(nk log n)
Space: O(nk)


At every call for range and k, we have to function of range, one is proportional and another is inversely proportional
So we have to find the middle point, the split point where the max of the 2 functions will be minimum
We can do binary search for that 
*/

class Solution {
public:
    int inf = 1e9;
    vector<vector<int>> dp;

    int call(int range, int k){
        if(k==0)  return inf;
        if(k == 1)  return range;
        if(range <= 0)  return 0;  
        
        int &mem = dp[range][k];
        if(mem != -1)  return mem;
        
        int lo = 1, hi = range;
        int ans = inf;

        while(lo<hi){
            int mid = (lo+hi)/2;

            int t1 = 1 + call(mid-1, k-1); //egg broken - increasing with value of mid
            int t2 = 1 + call(range-mid, k); //egg not broken - decreasing with value of mid

            if(t1 < t2)  lo = mid+1;
            else hi = mid;
        }

        return mem = 1 + max(call(lo-1, k-1) , call(range-lo, k)); //or, call(range-lo, k) -> same value
    }


    int superEggDrop(int k, int n) {
        dp = vector(n+1, vector(k+1,-1));
        return call(n,k);
    }
};
