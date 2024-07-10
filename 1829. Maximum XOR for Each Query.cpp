/*
Time: O(n * maxBit)
Space: O(1)
*/
class Solution {
public:
    //This function takes a xored_value and returns the number x having bit_counts = max_bit that result in xored_value ^ x to be maximized
    int ans_for(int val, int max_bit){
        int ans = 0;

        //traverse through bit from pos 0 to max_bit
        //if val has 0, we put 1, and if val has 1, we put 0 at that position
        for(int i=0;i<max_bit;i++){
            bool check_bit = val & (1<<i);

            if(!check_bit)
                ans = ans | (1<<i);
        }

        //cout<<val<<" "<<ans<<endl;
        return ans;
    }

    vector<int> getMaximumXor(vector<int>& nums, int maxBit) {
        int xr = 0;
        vector<int> ans;

        //removing the last element per iteration simply means adding one element per iteration in reverse 
        for(auto &u: nums){
            xr ^= u;
            ans.push_back(ans_for(xr, maxBit));
        }

        //since the iteration was reversed
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
