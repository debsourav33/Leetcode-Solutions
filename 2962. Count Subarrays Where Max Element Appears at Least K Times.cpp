//Time: O(n)
//Space: O(n)
// Min-window: For every index i, we will find the left-most index left, so that the window [left to i] contains at least k occurence of max
// that means, all subarrays ending in index i, and starting from indices [0 ... left] will have minimum k counts of max

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;

        int maxi = 0;
        for(auto u: nums)  maxi = max(maxi, u);

        int cnt = 0, left = 0;

        for(int i=0;i<nums.size();i++){
          if(nums[i]==maxi){
            cnt++;
          }

          while(cnt == k){
            if(nums[left] == maxi)  cnt--; //squeeze from left to find the window farthest from index 0 that has k counts of max
            left++;
          }

          ans += left;
        }

        return ans;
    }
};
