class Solution {
public:
    vector<int> a;
    int n;
    vector<vector<int>> dp;

    // O(N*K^2)  solution
    int call(int pos, int k){
      if(pos==n)  if(k!=0)  return INT_MAX;  else  return 0;
      if(k==0)  return INT_MAX;
      
      int &mem = dp[pos][k];
      if(mem!=-1)  return mem;

      int curr_sum = 0;
      int best = INT_MAX;

      //options:
      // - add this element to current sum and iterate to next element
      // - end this split and move to next split (call the recursive function with next idx)
      //when we end the split, the maximum between current sum and the result from recursive call should be the result for this split.. find the best split that minimizes this maximum
      for(int i=pos;i<n;i++){
        curr_sum += a[i];

        int next_max = call(i+1,k-1);
        int maxi = max(curr_sum,next_max);        

        best = min(best, maxi);
      }

      return mem = best;
    }

    int splitArray(vector<int>& nums, int k) {
      a = nums;
      n = nums.size();
      
      dp = vector(n, vector(k+1,-1));

      return call(0,k);     
    }
};
