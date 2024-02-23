/*
Approach: k-dimensional Dijsktra
*/

class Solution {
public:
    vector<vector<int>> dist;
    vector<vector<vector<int>>> v;
    int stops;

    struct node{
      int u, k, dist;

      node(int _u, int _k, int _dist){
        u = _u;
        k = _k;
        dist = _dist;
      }

      bool operator <(const node& nd) const{
        return dist > nd.dist;
      }
    };

    void dijkstra(int source){
      priority_queue<node> q;
      
      dist[source][0] = 0;
      q.push(node(source, 0, 0));

      while(!q.empty()){
        node nd = q.top();
        q.pop();

        int u = nd.u, k = nd.k, d = nd.dist;
        
        if(d != dist[u][k])  continue;
        if(k==stops+1)  continue;

        for(auto &adj: v[u]){
          int x = adj[0], cost = adj[1];

          if(dist[x][k+1] > dist[u][k] + cost){
            dist[x][k+1] =  dist[u][k] + cost;
            q.push(node(x, k+1, dist[x][k+1]));
          }
        }
      }
    }

    const int inf = 1000000009;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        stops = k;
        dist = vector(n,vector(k+2,inf)); //we can make k intermediate stops, +1 for the desination
        v = vector(n, vector<vector<int>>());
        
        for(auto &f: flights){
          v[f[0]].push_back({f[1],f[2]});
        }

        dijkstra(src);

        int ans = inf;
        for(int i=0;i<k+2;i++){
          //cout<<i<<" "<<dist[dst][i]<<endl;
          ans = min(ans, dist[dst][i]);

        }

        return ans == inf ? -1 : ans;

    }
};
