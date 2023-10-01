class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> suffix_sum;

        //calc suffix sum
        suffix_sum.push_back(nums[n-1]);
        for(int i=n-2;i>=0;i--){
          int suff = suffix_sum[n-2-i] + nums[i];
          suffix_sum.push_back(suff);
        }

        //don't take more than n elements from start and tail!
        int ans = n+1;

        //check without taking anything from start
        int pre_sum = 0;
        int needed = x - pre_sum;
        int suff = lower_bound(suffix_sum.begin(),suffix_sum.end(),needed) - suffix_sum.begin();
        if(suff<n && suffix_sum[suff]==needed)  ans = min(ans, suff+1);

        //pick one by one element from start and check if remaining is in tail
        for(int i=0;i<n;i++){
          pre_sum += nums[i];
          needed = x - pre_sum;

          //check without taking anything from end
          if(needed==0){
            ans = min(ans, i+1);
            break;
          }

          suff = lower_bound(suffix_sum.begin(),suffix_sum.end(),needed) - suffix_sum.begin();
          if(suff<n && suffix_sum[suff]==needed) ans = min(ans, i+1 + suff+1);
        }

        return ans < n+1 ? ans : -1;

    }
};
