//Time: O(n)
//Space: O(n)

//Squezee Window Technique
/*
For every index i, 
1. we will find the left-most index left, so that the window [left to i] contains k unique elements
2. we will find the left-most index right, so that the window [right to i] contains k-1 unique elements

that means, all subarrays ending in index i, and starting from indices [0 ... left] will have k unique elements
and         all subarrays ending in index i, and starting from indices [0 ... right] will have k-1 unique elements

-> which implies all subarrays ending in index i, and starting from indices [left ... right] will have k unique elements
so, add left-right to the answer
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> l_cnt, r_cnt;
        int l_uniq = 0, r_uniq = 0;

        int ans = 0;
        int left = 0, right = 0;

        for(int i=0;i<n;i++){
            int num = nums[i];


            if(l_cnt[num] == 0)  l_uniq++;
            
            if(r_cnt[num] == 0) r_uniq++;

            l_cnt[num]++;
            r_cnt[num]++;
            
            while(l_uniq == k+1){
                int left_val = nums[left];
                l_cnt[left_val]--;

                if(l_cnt[left_val] == 0)  l_uniq--;  //squeeze from left to find the window farthest from index 0 that has k uniq elements
                left++;
            }

            while(r_uniq == k){
                int right_val = nums[right];
                r_cnt[right_val]--;

                if(r_cnt[right_val] == 0)  r_uniq--;  //squeeze from left to find the window farthest from index 0 that has k-1 uniq elements
                right++;
            }

            //cout<<i<<" "<<(right-left)<<endl;
            ans += right - left; //subarrays (that ends in index i) having k elements = no. of subarrays having k elements - no. of subarrays having (k-1) elements 
        }


        return ans;
    }
};
