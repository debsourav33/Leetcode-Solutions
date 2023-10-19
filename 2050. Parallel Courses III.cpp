class Solution {
public:
    struct node{
      int u;
      int curr_dist;

      node(int _u, int _cost){
        u = _u;
        curr_dist = _cost;
      }
    };

    friend bool operator <(const node& a,const node& b) {
      return a.curr_dist < b.curr_dist; //max distance node first
    }

    int n;
    vector<vector<int>> v;
    vector<int> par, time, dist; 

    void dijkstra(){
      
      priority_queue<node> pq;

      for(int i=1;i<=n;i++){
        if(par[i]==0){  
          dist[i] = time[i];
          pq.push(node(i,dist[i]));
        }
      }

      while(!pq.empty()){
        node curr = pq.top();
        pq.pop();

        int u = curr.u; //don't need curr.curr_dist which is just used to sort inside priority_queue
        
        for(int adj: v[u]){
          if(dist[u] + time[adj] > dist[adj]){  //difference with typical dijkstra - we are looking for longest path
            dist[adj] = dist[u] + time[adj];
            pq.push(node(adj,dist[u]));
          }
        }
      }

    }


    int minimumTime(int _n, vector<vector<int>>& relations, vector<int>& _time) {
        n = _n;
        
        //node starts from 1, so offset
        time.push_back(0);
        for(auto t: _time){
          time.push_back(t);
        }
        
        
        v= vector(n+1, vector(0,0));
        par = vector(n+1, 0);
        dist = vector(n+1, 0);

        for(auto vec: relations){
          v[vec[0]].push_back(vec[1]);
          par[vec[1]]++;
        }

        dijkstra();

        int maxi = 0;
        for(int i=1;i<=n;i++){
          //printf("Course %d takes %d months\n",i,dist[i]);
          maxi = max(maxi, dist[i]);
        }


        return maxi;
    }
};
