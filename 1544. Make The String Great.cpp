
//Time, Space: O(n)
//When we traverse something and need to keep applying a operation over and over again until the condition is not met anymore, 
//good chance it's a stack problem

class Solution {
public:
    //ascii diff between small and capital letter = 32
    bool bad(char c, char h){
        return c == h + 32 || c == h - 32;
    }


    string makeGood(string s) {        
        stack<char> st;


        for(int i=0;i<s.length();i++){
            if(!st.empty() && bad(st.top(), s[i]))  st.pop(); //if bad neighbor found, we remove the current top and skip the neighbor
            else  st.push(s[i]);
        }


        string ret;
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }

        //stack has the good string in reverse order
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
