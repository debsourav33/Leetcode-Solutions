/*
Time: O(n)
Space: O(n)

Approach: Stack is needed because * and / have higher precedence than + and -
As we encounter number, push it to stack
 - if the number is after a '-', push the negative of that number
 - if the previous operator is '*' or '/', pop the stack and get recent most 2 values, do the * or / and push the result onto the stack
 - at the end, add all the numbers in stack (negative number means we are actually subtracting)
*/

class Solution {
public:
    int calculate(string s) {
        s = s + '+'; 
        stack<int> st;
        char last = ' ';

        int curr = 0;
        for(int i=0;i<s.length();i++){
            auto c = s[i];

            if(c==' ')  continue;

            if(c>='0' && c<='9')  curr = curr*10 + (c-'0');
            else{ //not a number? push the current number to stack
                st.push(curr);
                curr = 0;

                if(last=='*'){
                    int b = st.top();  st.pop();
                    int a = st.top();  st.pop();

                    st.push(a*b);
                }
                else if(last=='/'){ //careful, top element is divisor
                    int b = st.top();  st.pop();
                    int a = st.top();  st.pop();

                    st.push(a/b);
                    
                }
                else if(last=='-'){ //subtracting a positive number = adding its negative
                    int a = st.top();  st.pop();
                    st.push(-1*a);
                }

                last = c;
            }          
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
