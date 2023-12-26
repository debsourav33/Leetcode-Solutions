class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<int>> dp;

    int call(int n, int sum, int k){
      if(sum<0)  return 0;
      if(n==0)  return sum == 0;

      int &mem = dp[n][sum];
      if(mem!=-1)  return mem;

      long ans = 0;
      for(int i=1;i<=k;i++){
        ans += call(n-1,sum-i,k);
        ans %= mod;
      }

      return mem = ans;
    }


    int numRollsToTarget(int n, int k, int target) {
        dp = vector(n+1,vector(target+1,-1));
        return call(n,target,k);
    }
};
