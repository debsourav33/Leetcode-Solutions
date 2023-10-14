class Solution {
public:

    int n;
    vector<int> cost, time;
    int offset = 500;
    int dp[505][1005];

    //we can assign paid painter and free painter to any wall
    //but, free painter can only work if paid one is occupied
    //which is equivalent to:
    //the time used by paid painter >= time used by free painter
    //or, t >= 0
    //where, t = the time used by paid painter - time used by free painter
    int call(int pos, int t){
      if(pos==n)  return t>=0 ? 0 : 1e9;
      
      int &mem = dp[pos][t+offset];  //offset the index for negative time 
      if(mem != -1)  return mem;

      int o1 = 1e9, o2 = 1e9;
      
      //if t >= 500, free painter can do all the remaining walls, so any value over 500 is same!
      o1 = cost[pos] + call(pos+1,min(500,t+time[pos])); //paid painter
      o2 = call(pos+1,t-1); //free painter

      return mem = min(o1,o2);
    }

    int paintWalls(vector<int>& c, vector<int>& t) {
        cost = c;
        time = t;
        n = cost.size();

        memset(dp,-1,sizeof(dp));

        return call(0,0);

    }
};
