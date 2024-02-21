/*
Time Complexity: O(rows * cols^2) = O(N^3)
Memory Complexity: O(rows * cols)
*/

class Solution {
public:

    vector<vector<int>> pref;

    //O(N^2) calculation of prefix sum for each row
    void calc(vector<vector<int>>& mat){
            
      pref = vector(mat.size(), vector(mat[0].size(), 0));


      for(int i=0;i<mat.size();i++){
        pref[i][0] = {mat[i][0]};

        for(int j=1;j<mat[i].size();j++){
          pref[i][j] = pref[i][j-1] + mat[i][j];
        }
      }
    }

    //O(1) calculation of the sum from column c1 to column c2 for row 'row'
    int get_range_sum(int row, int c1, int c2){
      int st = c1 > 0 ? pref[row][c1-1] : 0;
      int endi = pref[row][c2];

      return endi - st;
    }

    //O(n^3)
    //From 0th row,
    //Use sliding window to find the sum from each column for each possible size
    //When traversing row by row, Use map to store prefix sum for a pair of columns
    int solve(vector<vector<int>>& mat, int target){
      int ans = 0;
      int rows = mat.size(), cols = mat[0].size();

      for(int size=1; size<=cols; size++)
      {
        for(int i=0; i+size<=cols; i++)
        {
          int sum = 0;
          unordered_map<int,int> m;
          m[0] = 1;
          for(int j=0;j<rows;j++)
          {
            sum += get_range_sum(j, i, i+size-1);
            int need = sum - target;
            if(m.count(need))  ans += m[need];
            m[sum]++;
          }
        }
      }

      return ans;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      calc(matrix);
      return solve(matrix, target);
    }
};
