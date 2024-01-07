class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int n = v.size();
        if(n<3)  return 0;

        vector<int> dp(n,-1);
        
        int ans = 0;
        dp[n-1] = dp[n-2] = 0;
        

        //if v1, v2 and v3 are arithmatic sequences (that means diff of v1 and v2 are same as v2 and v3),
        //then the valid sequences from v2,v3,.... must also remain valid sequences when they are appended by v1 at the begining
        for(int i=n-3;i>=0;i--){
          dp[i] = (v[i]-v[i+1] == v[i+1]-v[i+2]);
          if(dp[i])  dp[i] += dp[i+1];

          ans += dp[i];
        }

        return ans;
    }
};
