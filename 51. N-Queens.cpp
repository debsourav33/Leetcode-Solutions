/*
Time Complexity: o(n!)  (1st row, n choices.. 2nd row, n-1 choices.. 3rd row, n-2 choices...)
Space Complexity: O(1) (ignoring result array)

Use backtracking. At each row, we can have one queen in any of the n columns
We can easility check if the same column has an existing queen by using hashmap
What for diagonal?
Remember, for the same diagonal down-right, value of (row-column) will be same
And, for the same diagonal down-left, value of (row+column) will be same

So use 2 hashmaps for these two kind of diagonals
*/

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> v;

    int n;
    unordered_map<int,bool> col, diagR, diagL;

    bool is_valid(int r, int c){
        return (col.count(c) == 0 || col[c] == false) && 
                (diagR.count(r-c) == 0 || diagR[r-c] == false)  && 
                (diagL.count(r+c) == 0 || diagL[r+c] == false);
    }

    void call(int row){
        if(row==n){
            ans.push_back(v);
            return;
        }


        for(int i=0;i<n;i++){
            if(!is_valid(row,i))  continue;
            
            v[row][i] = 'Q';
            col[i] = true;
            diagR[row-i] = true;
            diagL[row+i] = true;

            call(row+1);

            //backtrack
            diagL[row+i] = false;
            diagR[row-i] = false;
            col[i] = false;
            v[row][i] = '.';
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        this->n = n;

        for(int i=0;i<n;i++){
            string s = "";
            for(int j=0;j<n;j++)  s += '.';
            v.push_back(s);
        }

        call(0);
        return ans;

    }
};
