class Solution {
public:
    vector<int> a;
    int dp[10004], n;
    
    int call(int pos){
        if(pos==n-1)  return 0;
        if(dp[pos]!=-1) return dp[pos];
        
        int ans = 1e9;
        for(int i=pos+1;i<=min(pos+a[pos],n-1);i++){
            ans = min(ans, 1 + call(i));
        }
        
        return dp[pos] = ans;
        
    }
    
    int jump(vector<int>& nums) {
        a = nums;
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        
        return call(0);
    }
};