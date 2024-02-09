class Solution {
public:

    //Bottom-up DP
    //Similar approach to LIS
    vector<int> largestDivisibleSubset(vector<int>& v) {
      int n = v.size();
      
      sort(v.begin(),v.end());

      vector<int> dp(n,1);
      vector<int> choice;
      for(int i=0;i<n;i++)  choice.push_back(i);

      dp[n-1] = 1;
      int max_idx = n-1;

      //for an element at i, find the idx j > i so that v[j]%v[i] = 0 and v[j] has maximum divisors
      for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
          if(v[j]%v[i]==0 && dp[i] < 1 + dp[j]){
            dp[i] = 1 + dp[j];
            choice[i] = j; //track path
          }
        }

        if(dp[i] > dp[max_idx]){
          max_idx = i;
        }
      }

      int idx = max_idx;
      vector<int> ret = {v[idx]};

      //print path    
      while(choice[idx]!=idx){
        idx = choice[idx];
        ret.push_back(v[idx]);
      }

      return ret;
    }
};
