class Solution {
public:
    vector<vector<int>> dist;
    int n, ans = 10000007, dp[12][1<<13];
    vector<vector<int>> v;
    
    //find out all pair-distance
    void floyd_warshal(){
      //memset(dist, 0, sizeof(dist));
      dist = vector(n, vector(n, 10000007));

      for(int i=0;i<n;i++)  dist[i][i] = 0;

      for(int i=0;i<n;i++)
        for(auto j: v[i])
          dist[i][j] = dist[j][i] = 1;        
      

      for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++){
            if(dist[i][k] + dist[k][j] < dist[i][j])
              dist[i][j] = dist[i][k] + dist[k][j];
          }
    }

    int setbit(int mask, int pos){
      return mask | (1<<pos);
    }

    int checkbit(int mask, int pos){
      return mask & (1<<pos);
    }

    //dp state: the visited nodes so far (mask) and the last visited node (from where we go to next node)
    int call(int last, int mask){
      if(mask == ((1<<n)-1))  return 0;
      
      int &mem = dp[last][mask];
      if(mem!=-1)  return mem;

      int ans = 100000007;

      for(int i=0;i<n;i++){
        if(checkbit(mask,i)==0){
          int d = dist[last][i];
          int updated_mask = setbit(mask, i);
          ans = min(ans, d + call(i, updated_mask));
        }
      }
      return mem = ans;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        v = graph;
        n = graph.size();
        memset(dp,-1,sizeof(dp));

        floyd_warshal();

        int ans = 10000007;
        
        for(int i=0;i<n;i++)
          ans = min(ans, call(i, setbit(0,i)));
        return ans;
    }
};
