/*
Time: O(n*a*l) (a = max absent days, l = max consecutive late )
Space: O(n*a*l)

DP
State: current day, no. of absent days (< 2), no. of consecutive late days (< 3)
*/

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9+7;


    int call(int n, int ab, int late){
        if(n == 0)  return 1;
        
        int &mem = dp[n][ab][late];
        if(mem != -1)  return mem;

        int ans = call(n-1, ab, 0) % mod; //present, consecutive late resets to 0
        if(ab == 0) ans = (ans + call(n-1,ab+1, 0)) % mod; //absent, consecutive late resets to 0
        if(late<2)  ans = (ans + call(n-1,ab,late+1)) % mod; //late

        return mem = ans;
    }

    int checkRecord(int n) {
        dp = vector(n+1,vector(2, vector(3, -1)));
        return call(n,0,0);
    }
};
