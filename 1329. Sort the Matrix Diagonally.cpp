/*
Time: O(n*mlog(n*m))
Space: O(n*m)

The idea is, if two elements belong to the same main diagonal (top-left to bottom-right),
their r-c will be same (where r is the row and c is the column number)
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,priority_queue<int, vector<int>, greater<int>>> m;
        
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> ret(row, vector<int>(col));

        //traverse entire matrix
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                int diff = r-c;
                m[diff].push(mat[r][c]); //push to pq
            }
        }


        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                int diff = r-c;
                ret[r][c] = m[diff].top();
                m[diff].pop(); 
            }
        }

        return ret;

    }
};
