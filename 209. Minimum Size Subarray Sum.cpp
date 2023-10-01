class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9;
        int sum = 0;
        int left = 0;

        for(int i=0;i<nums.size();i++){
          sum += nums[i];

          if(sum>=target){
            //target found, minimize left border
            while(sum>=target){
              sum -= nums[left];
              left++;
            }

            //we stopped one index right of the lower border
            int range = i - (left-1) + 1;
            ans = min(ans, range);
          }
        }

        return ans < 1e9 ? ans : 0;
    }
};
