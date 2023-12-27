class Solution {
public:
    int rows, cols, total;
    vector<int> sz;
    vector<int> par;
    vector<vector<int>> grid;


    int r[4] = {1,-1,0,0};
    int c[4] = {0,0,1,-1};
    

    int find(int pos){
      if(par[pos]==pos)  return pos;

      return par[pos] = find(par[pos]);
    }

    int unions(int p1, int p2){
      p1 = find(p1);
      p2 = find(p2);

      if(p1==p2)  return 0;

      if(sz[p2]<=sz[p1]){
        par[p2] = p1;
        sz[p1] += sz[p2];
      }
      else{
        par[p1] = p2;
        sz[p2] += sz[p1];
      }

      
      return 1;
    }

    void dfs(int x, int y){
      int p = x * cols + y;
      
      for(int i=0;i<4;i++){
        int cx = x+r[i], cy = y+c[i];

        if(cx<0 || cx>=rows || cy<0 || cy>=cols)  continue;

        if(grid[cx][cy]==0)  continue;

        int cp = cx * cols + cy;
        if(find(p) == find(cp))  continue;

        unions(p,cp);
        dfs(cx,cy);
      }
    }


    int largestIsland(vector<vector<int>>& grid) {
      rows = grid.size();
      cols = grid[0].size();
      this->grid = grid;

      total = rows*cols+1;

      sz = vector(total, 1);
      for(int i=0;i<total;i++)  par.push_back(i);

      for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
          int p = i*cols + j;
          if(grid[i][j] && find(p)==p)  dfs(i,j);
        }

      int ans = 0;
      for(int i=0;i<total;i++){
        //cout<<par[i]<<": "<<sz[par[i]]<<endl;
        ans = max(ans, sz[par[i]]);
      }

      //for every 0 cell
      //get set of components (parents) of neighbor 1 cells
      //add the sizes of those components
      for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
          if(grid[i][j]) continue;
          
          int total = 1;
          set<int> pars;

          for(int k=0;k<4;k++){
            int cx = i+r[k], cy = j+c[k];
            if(cx<0 || cx>=rows || cy<0 || cy>=cols)  continue;
            

            if(grid[cx][cy]==0)  continue;

            int p = cx*cols + cy;
            //cout<<i<<","<<j<<" $ "<<p<<endl;
            pars.insert(find(p));
          }

          
          for(auto u: pars){
            total += sz[u];
          }

          ans = max(ans, total);
        }
      }



      return ans;
        
    }
};
