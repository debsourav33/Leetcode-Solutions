/*
Stack Soln

Time = Space = O(n)

Top left cell of each rectangular group will have up and left neighbors non-farm (out of grid or forest) 
Bottom cell of each rectangular group will have bottom and right neighbors non-farm (out of grid or forest) 

Now the top and bottom can appear out-of-order if we just traverse row-column wise
But one thing that is sure that any bottom will always have the latest top as its correspondant
So we can just use stack to find the latest top whenever we find a bottom!

*/

class Solution {
public:
    int m, n;
    vector<vector<int>> land;

    bool is_farm(int i, int j){
        if(i<0 || i>=m || j<0 || j>=n )  return false;

        return land[i][j] == 1;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size(), n = land[0].size();
        this->land = land;

        vector<vector<int>> ret;

        stack<pair<int,int>> top, bottom;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j] == 0)  continue;

                //top and left cells not farms? - starting of a grp!
                if(!is_farm(i-1,j) && !is_farm(i,j-1))  top.push({i,j});
                //bottom and right cells not farms?- end of a grp!
                if(!is_farm(i,j+1) && !is_farm(i+1,j))  bottom.push({i,j});

                //Bottom found! Latest top is its correspondant
                if(!bottom.empty()){
                    ret.push_back({top.top().first, top.top().second,
                                    bottom.top().first, bottom.top().second});
                    
                    top.pop();
                    bottom.pop();
                }
            }
        }

        return ret;
    }
};
