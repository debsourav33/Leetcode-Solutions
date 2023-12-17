class Solution {
public:
    int n;
    vector<int> a;
    vector<vector<int>> dp;
    int target = 0;

    int can(int pos, int sum){
      if(sum==target)  return 1;
      if(sum>target || pos==n)  return 0;
      
      if(dp[pos][sum]!=-1)  return dp[pos][sum];

      //2 options -> take the number or skip it
      return dp[pos][sum] = can(pos+1, sum) || can(pos+1, sum+a[pos]);
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        
        int sum = 0;
        for(auto u: nums)  sum += u;
        
        if(sum%2)  return false;
        target = sum/2;
        
        dp = vector(n,vector(target+1,-1));

        a = nums;
        return can(0,0);
    }
};
