/*
Time: O(m*n(log m*n))
Space: O(m*n)

This is a graph problem with edges having values = max(absolute_difference between the two cells, the minimum effort till parent cell is reached)
To solve the weighted graph problem, simply use dijstra
*/

class Solution {
public:
    const int inf = 1e9;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int dijk(vector<vector<int>>& g){
        int r = g.size(), c = g[0].size();

        //for any particular cell, dist is the best minimum effort required to travel to that cell (from 0,0)
        vector<vector<int>> dist(r, vector<int>(c, inf));
        
        auto cmp = [](vector<int>& v1, vector<int>& v2){
            return v1[0] > v2[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        dist[0][0] = 0;
        pq.push({dist[0][0],0,0});
        

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int x = node[1], y = node[2];
            if(dist[x][y] != node[0])  continue;

            //cout<<x<<" "<<y<<endl;

            for(auto& d: dir){
                int ax = x+d[0], ay = y+d[1];
                
                if(ax == r || ax < 0 || ay == c || ay < 0)  continue; //validity check

                int ab_diff = abs(g[x][y] - g[ax][ay]);
                int new_dist = max(dist[x][y], ab_diff); //finding edge value
                
                if(dist[ax][ay] > new_dist){
                    dist[ax][ay] = new_dist;
                    pq.push({dist[ax][ay], ax, ay});
                }
            }

            
        }

        return dist[r-1][c-1]; //the minimum effort of the route till the last cell!
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijk(heights);
    }
};
