class Solution {
public:
    //TC: O(d^2), SC: O(d) (d = digits count)
    int monotoneIncreasingDigits(int n) {
        //base case
        if(n==0)  return 0;

        bool smaller = false;
        
        vector<int> digits;
        while(n){
            digits.push_back(n%10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        stack<int> st;
        st.push(digits[0]);

        //we will try to push the current digit
        //if it breaches monotone property, we will pop the stack and decrement the value by one
        //again breach check with the top of stack and same process repeats
        //once the breach happens and we decrement a MSB, all subsequent LSB digits can be 9        
        while(st.size() < digits.size()){
            if(smaller)  st.push(9);
            else{
                int curr = digits[st.size()];
                while(!st.empty() && curr<st.top()){
                    curr = st.top() - 1;
                    st.pop();

                    smaller = true;
                }

                st.push(curr);
            }
        }

        
        //get rid of leading zeroes
        //reverse the stack and store it in tmp
        stack<int> tmp;
        while(!st.empty()){
            //cout<<st.top()<<endl;

            tmp.push(st.top()); 
            st.pop();
        }

        //now leading zeroes won't have any effect
        int res = 0;
        while(!tmp.empty()){
            int val = tmp.top();
            tmp.pop();

            res = res*10 + val;
        }

        return res;
    }
};
