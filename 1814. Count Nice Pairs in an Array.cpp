class Solution {
public:
    //    a + rev(b) = b + rev(a)
    // => a - rev(a) = b - reb (b)

    //So, calculate all a[i] - rev(a[i]) and look for equal amounts

    int rev(int num){
      int ret = 0;

      while(num){
        ret = ret * 10 + num % 10;
        num /= 10;
      }

      return ret;
    }

    int countNicePairs(vector<int>& nums) {
        for(auto &u: nums){
          u -= rev(u);
          
        }

        int last = 0;
        long ans = 0;

        sort(nums.begin(),nums.end(),greater<int>());


        for(int i=1;i<nums.size();i++){
          if(nums[i]==nums[i-1])  continue;
          else{
            long same_cnt = i-last;
            ans += (same_cnt * (same_cnt-1))/2;
            
            last = i;
          }
        }

        long same_cnt = nums.size()-last;
        ans += (same_cnt * (same_cnt-1))/2;

        return ans % 1000000007;
    }
};
