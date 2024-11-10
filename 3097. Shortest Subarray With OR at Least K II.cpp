/*
Time: O(n)
Space: O(1)

Squeeze Window:

   Squeeze the sliding window from left until the current window's bitwise or reaches below k

*/

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = n+1;
        int bor = 0;

        int left = 0;
        vector<int> cnt(31, 0);

        //Squeeze the sliding window from left until the current window's bitwise or reaches below k
        for(int i=0;i<n;i++){
            int u = nums[i];
            //bor |= u;

            for(int i=0;i<31;i++){
                if( (u & (1<<i)) != 0 )  cnt[i]++;
                if(cnt[i] == 1)  bor = bor | (1<<i);  //set bit
            }
            

            while(left<=i && bor >= k){
                ans = min(ans,i-left+1);

                int x = nums[left];
                for(int i=0;i<31;i++){
                    if( (x & (1<<i)) != 0 )  cnt[i]--;
                    if(cnt[i] == 0)  bor = bor & ~(1<<i); //reset bit
                }
                left++;
            }
        }


        return ans == n+1 ? -1 : ans;
    }
};
