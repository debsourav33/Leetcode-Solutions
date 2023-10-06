class Solution {
public:
    int dp[60][2];

    int call(int n, int divided_part){
      if(n<=1)  return 1;
      if(dp[n][divided_part]!=-1)  return dp[n][divided_part];

      int maxi = divided_part ? n : 1;  //if its a divided part (like, 4 and 3 are divided parts of 7), then we can consider returning the whole value too
      for(int i=1;i<n;i++){
        maxi = max(maxi, i * call(n-i, 1));
      }

      return dp[n][divided_part] = maxi;
    }

    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));

        return call(n,0);
    }
}; 
