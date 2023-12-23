class Solution {
public:
    vector<int> par;
    vector<int> rank;  //height of longest sub stree

    int find(int u){
      if(par[u]==u)  return u;

      return par[u] = find(par[u]);
    }

    void unions(int u, int v){
      u = find(u);
      v = find(v);

      //pick the longer tree's parent 
      if(rank[u]==rank[v]){
        par[u] = v;
        rank[v]++; //new rank of v = new child u (1) + rank[u]
      }
      else if(rank[u] < rank[v]){
        par[u] = v; //no need to update rank as rank[v] >= new child u (1) + rank[u]
      }
      else{
        par[v] = u;
      }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = 1005;

      par = vector(n,-1);
      rank = vector(n,0);
      for(int i=0;i<n;i++)  par[i] = i;

      for(auto edge: edges){
        int p1 = find(edge[0]);
        int p2 = find(edge[1]);
        
        if(p1==p2)   return edge;
        unions(p1,p2);
      }

      return {};
    }
};
