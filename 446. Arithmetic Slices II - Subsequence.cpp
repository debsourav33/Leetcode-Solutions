/*
Although the solution is O(N^3) at worst case (all equal values [7,7,7,7...,7]),
The constraint of answer fitting in a 32 bit integer means the worst case is never reached and we can rely on O(N^2*logN) order of time
*/

class Solution {
public:
    const int inf = 1e9;
    int numberOfArithmeticSlices(vector<int>& a) {
      unordered_map<int,vector<int>> indices;

      int n = a.size();
      if(n<3)  return 0;

      vector<vector<int>> dp(n,vector(n,0));

      for(int i=0;i<n;i++){
        int val = a[i];
        if(indices.count(val)==0)  indices[val] = {};
        indices[val].push_back(i);
      }

      int ans = 0;
      dp[n-2][n-1] = 0;

      for(int i=n-3;i>=0;i--){
        int first = a[i];

        for(int j=i+1;j<n-1;j++){
          /* handle overflow using long */
          long second = a[j];
          long diff = second-first;

          long need = second + diff;
          if(need > INT_MAX || need < INT_MIN)  continue;

          if(indices.count(need)==0)  continue;
          
          /*for the values at indices i and j, find all indices k having value equal to 'need'
          Then, we can just make one new sequence by appending a[i] to the sequences that are stored in dp[j][k]
          */
          auto &ind = indices[need];
          int st = upper_bound(ind.begin(),ind.end(),j) - ind.begin();

          dp[i][j] = 0;

          //we can have new sequences for all the indices pos
          for(int k=st;k<ind.size();k++){
            int pos = ind[k];      

            //add 1 for the sequence a[i],a[j],a[pos]
            //dp[j][pos] holds all sequences starting with a[j],a[pos],.. -> each of these sequences can contribute one more when a[i] is prepended to them 
            dp[i][j] += (1+dp[j][pos]);
            
          }

          ans += dp[i][j];
        }
      }
        

      return ans;
    }
};
