/*
Time: O(n^2)
Space: O(n^2)

DP States: no. of As, clipboard size (copied 'A's)
Options: from each state, we can either increase As to As+clipboard size, or increase clipboard size to As
*/

class Solution {
public:
    int target;
    vector<vector<int>> dp;

    //top_down
    int call(int n, int clipped){
        if(n > target || clipped > target)  return 1e9;
        if(n == target)   return 0; 
        
        if(dp[n][clipped] != -1)  return dp[n][clipped];

        int ans = 1e9;
        if(clipped > 0) ans = min(ans, 1 + call(n+clipped, clipped)); //paste
        if(clipped < n) ans = min(ans, 1 + call(n, n)); //copy

        return dp[n][clipped] = ans;
    }

    int bottom_up(int n){
        //base case
        for(int i=0;i<=n;i++)
            dp[n][i] = 0; //if we already have n 'A's, we don't need anymore operation
        
        for(int i=n-1;i>=1;i--){
            for(int clipped=n; clipped>=0;clipped--){ //for each possible i 'A's and clipped 'A's on clipboard, we have 2 options -> paste clipped (i becomes i+clipped), or copy everything (clipped becomes i)
                if(i+clipped > n)  dp[i][clipped] = dp[i][i];
                else  dp[i][clipped] = min(1 + dp[i+clipped][clipped], 
                                    1 + dp[i][i]);
            }
        }

        return dp[1][0];
    }
    
    int minSteps(int n) {
        target = n;
        dp = vector(n+1, vector(n+1, (int)1e9));

        

        return bottom_up(n);
    }
};
