class Solution {
public:
    int n;
    vector<int> a;
    vector<int> dp;
    int target = 0;

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        
        int sum = 0;
        for(auto u: nums)  sum += u;
        if(sum%2)  return false;
        target = sum/2;

        dp = vector(target+1,-1);

        vector<int> sums = {0};

        for(auto u: nums){  //for every element
          vector<int> new_sums;
          for(auto sum: sums){  //try adding to each of the previously achieved sum
           
           //2 options -> take it or don't
           //case 1: take
           int taken_sum = sum+u;
           if(taken_sum > target)  continue;
           if(dp[taken_sum]!=-1)  continue; //already achieved this sum
           
           dp[taken_sum] = 1;
           new_sums.push_back(taken_sum);
           
           //case 2: don't take -> do nothing

          }

          for(auto s: new_sums)  sums.push_back(s);
        }

        return dp[target] == 1;
    }
};
