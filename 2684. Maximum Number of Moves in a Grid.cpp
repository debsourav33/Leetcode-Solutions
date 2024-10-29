/*
Time: O(row*col)
Space: O(row*col)

Bottom-up DP:

Since we can go to only next column and row-1,row,row+1 -> we need to process the rows first for each column (starting at the bottom most).

This order is necessary because determining the value for cell (i, j) depends on the values of the cells in the next column, namely (i + 1, j + 1), (i, j + 1), and (i - 1, j + 1). Thus, when processing column j, we must already have the values for all rows in column j + 1.


Space Optimization: We only need DP table for next column (not the columns following that)
*/

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> dp(r, 0); //Space Optimization: We only need DP table for next column (not the columns following that)

        for(int j=c-1;j>=0;j--){ //for each column
            vector<int> tmp(r, 0);

            for(int i=r-1;i>=0;i--){ //process all the rows

                if(i+1 < r && j+1 < c && grid[i][j] < grid[i+1][j+1])  tmp[i] = max(tmp[i], 1 + dp[i+1]);
                if(i-1 >= 0 && j+1 < c && grid[i][j] < grid[i-1][j+1])  tmp[i] = max(tmp[i], 1 + dp[i-1]);
                if(j+1 < c && grid[i][j] < grid[i][j+1])  tmp[i] = max(tmp[i], 1 + dp[i]);
            }

            dp = tmp;
        }

        int ans = 0;
        for(int i=0;i<r;i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};
