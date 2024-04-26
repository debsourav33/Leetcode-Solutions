/*
Time= O(n*n)
Space= O(n)

Do DP
For previous row, find the minimum and 2nd minimum indices
For current row and each column, if the column is the same as minimum col, pick the 2nd minimum, otherwise pick the first minimum index

*/

class Solution {
public:
    //function that finds the minimum and 2nd minimum indices of a row
    pair<int,int> get2Min(vector<int>& v){
        int m = 0, m2 = -1; 
        for(int i=1;i<v.size();i++){
            if(v[i] <= v[m]){
                m2 = m;
                m = i;
            }
            else if(m2 == -1 || v[i] <= v[m2]){
                m2 = i;
            }
        }

        return {m,m2};
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); //rows = cols = n

        //edge case (optional)
        //if(n == 1){
          //  return grid[0][0];
        //}

        for(int i=1;i<n;i++){
            auto p = get2Min(grid[i-1]);
            //cout<<i-1<<" "<<p.first<<" "<<p.second<<endl;
            
            for(int j=0;j<n;j++){
                if(p.first != j)
                    grid[i][j] += grid[i-1][p.first]; //tabulating dp on the input array
                else
                    grid[i][j] += grid[i-1][p.second]; 
            }
        }

        int best_idx = get2Min(grid[n-1]).first;
        return grid[n-1][best_idx]; //return the minimum sum gained till any column in last row
    }
};
