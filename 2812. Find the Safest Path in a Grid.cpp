/*
Time: O(m*n(log m*n))
Space: O(m*n)

1. Run BFS to find safeness value of all cells
2. Then it becomes a graph problem with edges having values = max(adjacent cell's safeness, the maximum safeness factor of the route till parent cell)
To solve the weighted graph problem, simply use dijstra
*/
class Solution {
public:
    int r,c;
    const int inf = 1e9;
    vector<vector<int>> level, dist;

    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    // BFS to find safeness value of all cells
    void bfs(vector<vector<int>>& g){
        queue<vector<int>> q;
        for(int i=0;i<r;i++){
            for(int j=0; j<c; j++){
                if(g[i][j] == 1){
                    level[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto u = q.front();
            q.pop();

            int curr_level = level[u[0]][u[1]];
            for(auto& d: dir){
                int adj_x = u[0]+d[0], adj_y = u[1]+d[1];
                if(adj_x < 0 || adj_y < 0 || adj_x == r || adj_y == c)  continue;
                if(curr_level + 1 < level[adj_x][adj_y]){
                    level[adj_x][adj_y] = curr_level + 1;
                    q.push({adj_x, adj_y});
                }
            }
        }
    }

    
    // solve the weighted graph problem with dijstra
    int dijkstra(vector<vector<int>>& g){
        auto cmp = [](vector<int>& v1, vector<int>& v2){
            return v1[2] < v2[2]; //we want max factor to expand first!
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        dist[0][0] = level[0][0]; 
        pq.push({0,0,dist[0][0]});
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();

            int curr_level = u[2];

            if(curr_level != dist[u[0]][u[1]])  continue; //not the best path till this cell
            if(g[u[0]][u[1]] == 1)  continue; //no need to explore thief cell
            if(u[0]==r-1 && u[1]==c-1)  return curr_level;  //reached end!

            for(auto& d: dir){
                int adj_x = u[0]+d[0], adj_y = u[1]+d[1];
                if(adj_x < 0 || adj_y < 0 || adj_x == r || adj_y == c)  continue;
                
                int adj_level = min(curr_level, level[adj_x][adj_y]);

                if(adj_level > dist[adj_x][adj_y]){ //better path found!
                    dist[adj_x][adj_y] = adj_level;
                    pq.push({adj_x, adj_y,dist[adj_x][adj_y]});
                }
            }
        }    

        return 0;

    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        level = vector(r, vector(c, inf));
        dist = vector(r, vector(c, 0));

        bfs(grid);
        /*
        for(int i=0;i<r;i++){
            for(int j=0; j<c; j++){
                printf("%d ",level[i][j]);
            }
            puts("");
        }
        */

        return dijkstra(grid);
    }
};
