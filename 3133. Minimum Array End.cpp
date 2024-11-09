/*
Beautiful Problem

Time: O(1) ( = O(64))
Space: O(1)

Observation:
   1. The answer must be minimum of x, because if we take a value k < x, then the bitwise AND of k and x will be less than x
   2. The numbers we take must have the same set bits in the same positions as x (otherwise, bitwise AND will cancel one out)


    So take the minimum number as x. Then try to placing an 1 bit in an 0-bit position of x one by one such that we get n numbers in ascending order.
    If you think about it, it's just adding n to X's 0-BIT POSITIONS
*/


class Solution {
public:
    long long minEnd(int n, int x) {
        //The answer must be minimum of x, because if we take a value k < x, then the bitwise AND of k and x will be less than x
        long long ans = x;

        int curr = 0;
        n--;

        //try to placing an 1 bit in an non-set bit position of x one by one such that we get n numbers in ascending order.
        while(n){
            int bit = (n&1 == 1);
            cout<<bit<<endl;
            n = n >> 1;

            //finding out the next 0-bit
            while( (ans & (1LL<<curr)) != 0 ){
                curr++;
            }

            if(bit)  ans = ans | (1LL<<curr);
            curr++;
        }

        return ans;

    }
};
