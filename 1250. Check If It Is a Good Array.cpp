class Solution {
public:
    /*
    Pick any subset (a,b,c) .. We can only reach gcd(a,b,c) by multiplying each item with any multiplier.
    As our aim is to reach gcd of 1, we can always get closer to target by picking the entire set
    */
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];

        for(int i=1;i<nums.size();i++){
          res = __gcd(res,nums[i]);
        }

        return res==1;
    }
};
