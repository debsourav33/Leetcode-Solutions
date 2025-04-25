/*
Time: O(32) = O(1)
Space: O

*/

class Solution {
    public int getSum(int a, int b) {
        while(b != 0){ //after first iteration, b holds the carry bits (on their rightful place), a holds the sum without the carry, so add b and a to get sum with carry
 
            int carry = a & b; //bitwise and gives us carry bits (1 & 1 = carry!)

            a = a ^ b; // a holds sum-without-carry, which is what xor gives us ( 1 ^ 1 = 0, 0 ^ 1 = 1, 1 ^ 0 = 1)

            // but we need to add carry bits to 1 bit on the left (towards MSB)
            carry = carry << 1;
            b = carry; 
        }

        // when b becomes 0 (no carry), a (which holds sum without carry) holds the real sum!
        return a;
    }
}
