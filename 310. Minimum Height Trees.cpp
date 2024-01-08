/*
Run double bfs to find the two farthest nodes (on the diameters)
Then run one bfs from each of these 2 nodes and track the maximum level (call, ml) of all the nodes.
MHT roots are those that have minimum ml(s)
*/

class Solution {
public:
    int n;
    vector<vector<int>> v;
    vector<int> level[2];
    
    void bfs(int source, int pos){
      queue<int> q;
      q.push(source);
      level[pos][source] = 0;

      while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto adj: v[u]){
          if(level[pos][adj]!=-1)  continue;

          level[pos][adj] = level[pos][u] + 1;
          q.push(adj);
        }
      }
    }

    int farthest(int pos){
      int f = 0;
      for(int i=1;i<n;i++)  if(level[pos][i] > level[pos][f])  f = i;

      return f;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ret;
        this->n = n;
        
        
        level[0] = vector(n,-1);
        level[1] = vector(n,-1);
        
        for(int i=0;i<n;i++)  v.push_back({});
        
        for(auto edge: edges){
          int x = edge[0], y = edge[1];
          v[x].push_back(y);
          v[y].push_back(x);
        }
  
        int f1, f2;

        bfs(0,0);
        
        f1 = farthest(0);
        bfs(f1,1);
        f2 = farthest(1);

        //cout<<f1<<" "<<f2<<endl;

        level[0] = vector(n,-1);
        level[1] = vector(n,-1);

        bfs(f1,0);
        bfs(f2,1);
        
        int min_lvl = 1e9;
        for(int i=0;i<n;i++){
          //cout<<i<<": "<<level[0][i]<<" "<<level[1][i]<<endl;
          int lvl = max(level[0][i],level[1][i]);
          min_lvl = min(lvl, min_lvl);
        }

        
        for(int i=0;i<n;i++){
          int lvl = max(level[0][i],level[1][i]);
          if(lvl==min_lvl) ret.push_back(i);
        }
        

        return ret;
    }
};
