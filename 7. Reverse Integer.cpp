/*
Time: O(n)
Space: O(1)

Take care of the overflow by comparing with INT_MAX and INT_MIN according to the sign
*/

class Solution {
public:
    int reverse(int num) {
        int neg = false;
        if(num < 0){
            neg = true;
        }

        int res = 0;

        while(num){
            int d = abs(num % 10); //last digit extraction -> we only care about the digit value
            num /= 10; //last digit removal

            // overflow check
            if(!neg){
                // if res > INT_MAX/10 -> multiplying 10 will surely cause overflow
                // if res == INT_MAX/10 and the digit d is greater than the last digit of INT_MAX -> overflow
                if(res > INT_MAX/10 || (res == INT_MAX/10 && d > INT_MAX%10))  return 0;
            }
            else{ // remember - negative max (INT_MIN) is one more than positive max (INT_MAX)
                if(res > INT_MAX/10 || (res == INT_MAX/10 && d > INT_MAX%10+1))  return 0;
            }

            //Warning: OVERFLOW!
            res = res * 10 + d;
        }

        cout<<res<<endl;
        return neg ? -res : res;
    }

};
