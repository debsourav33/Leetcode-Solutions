class Solution {
public:

    const int mod = 1e9+7;
    int n;
    vector<vector<int>> dp; //integer array causes stack overflow


    int call(int pos, int steps){
      if(steps==0)  return pos==0;

      int &mem = dp[pos][steps];
      if(mem!=-1)  return mem;

      int o1 = call(pos,steps-1);
      int o2 = pos>0 ? call(pos-1,steps-1) : 0;
      int o3 = pos<n-1 ? call(pos+1,steps-1) : 0;

      int val = ((o1+o2) % mod + o3) % mod;
      return mem = val;

    }

    int numWays(int steps, int arrLen) {
        n = min(steps,arrLen); //we can't go beyond steps length


        dp = vector(n+1, vector(steps+1,-1));
        return call(0,steps);
    }
};
