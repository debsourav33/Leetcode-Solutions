class Solution {
public:
    const int inf = -1e7+7;
    int n, dp[100005][4];
    vector<int> v;

    int call(int pos, int state){
        if(state==4 || n==pos)  return 0;
        if(dp[pos][state]!=-1) return dp[pos][state];

        int c1 = call(pos+1, state);
        int c2 = call(pos+1, state+1) + (state % 2 == 0 ? -1 * v[pos] : v[pos]);

        return dp[pos][state] = max(c1,c2);
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        v= prices;
        for(int i=0;i<1e5+5;i++) for(int j=0;j<4;j++) dp[i][j] = -1;

        return call(0,0);
    }
};
