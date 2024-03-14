/*
Time: O(n)
Space: O(n)

Approach: Stack is needed because * and / have higher precedence than + and -
As we encounter number, push it to stack
 - if the number is after a '-', push the negative of that number
 - if the current character is ')', push INT_MAX if it is after '+', or INT_MIN if it is after -
 - if the current character is ')', keep popping the stack until you find a open bracket, depending on the sign of the open bracket, push the sum or the negative of the sum
 - at the end, add all the numbers in stack (negative number means we are actually subtracting)
*/


class Solution {
public:
    const int open_p = INT_MAX;
    const int open_p_neg = INT_MIN;
        
    int calculate(string s) {
        stack<int> st;
        char last = ' ';

        s += '+'; //placeholder last character

        int curr = 0;
        for(auto &c: s){
            if(c==' ')  continue;

            if(c>='0' && c<='9')  curr = curr*10 + (c-'0');
            else if(c=='('){
                if(last=='-'){
                    puts("open neg");
                    st.push(open_p_neg);
                }
                else{
                    st.push(open_p);
                    puts("open");
                }

                last = c;
            }
            else{
                if(last=='-'){
                    st.push(-1*curr);
                    curr = 0;
                }
                else{
                    st.push(curr);
                    curr = 0;
                }

                //make sure curr is pushed before the ')' is handled
                if(c==')'){
                    int sum = 0;
                    while(st.top() != open_p && st.top() != open_p_neg){
                        sum += st.top();
                        st.pop();
                    }

                    //one more pop needed to get rid of the open_p at top
                    if(st.top()==open_p){
                        st.pop();
                        st.push(sum);
                    }
                    else{
                        st.pop();
                        st.push(-1 * sum);
                    }
                }

                last = c;
            }

            
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top(); st.pop();
        }

        return ans;
    }
};
