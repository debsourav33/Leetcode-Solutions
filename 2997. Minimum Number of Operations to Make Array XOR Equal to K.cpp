/*
Time: O(n)
Space: O(n)

Calculate the xor of all numbers = res
Then for each position, if the bit in res and k don't match, 
we know we have to pick any number in the array and flip a bit in that position (fliping a bit in any number will flip the bit in the resultant xor)
*/

class Solution {
public:
    int checkBit(int &u, int &p){
        return (u & (1 << p)) > 0;
    }

    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for(auto &u: nums)  res ^= u;

        int ans = 0;
        for(int i=0;i<31;i++){
            if(checkBit(res,i) != checkBit(k,i))  ans++; //bit mismatch ! need one operation
        }
        return ans;
    }
};
