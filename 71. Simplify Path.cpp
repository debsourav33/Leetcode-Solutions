/*
Time: O(N)
Space: O(N)

Maintain stack (don't forget to reverse it at the end!)

Version 2: Use stringstream(str) ss with getline(ss, tmp, '/') where '/' is the delimeter
*/

class Solution {
public:
    string simplifyPath(string s){
        int n = s.length();
        stack<string> st; // dirs

        stringstream ss(s);
        string cmd;

        while(getline(ss, cmd, '/')){
            

            //get rid of multiple '/'
            // NO NEED! getline(ss, cmd, '/') is taking care of that
            // while(i<n && s[i] == '/'){
            //     i++;
            // }

            if(cmd=="" || cmd == "."){ //stay in curr dir
                //don't care
            }
            else if(cmd == ".."){ //go back
                if(!st.empty())  st.pop();
            }
            else{ //valid directory
                st.push(cmd); 
            }
        }

        //edge case
        if(st.empty())  return "/";

        string ret = "";

        //reverse the stack
        stack<string> tmp;
        while(!st.empty()){
            tmp.push(st.top());
            st.pop();
        }

        st = tmp; //reversed stack

        while(!st.empty()){
            ret += "/";  //we shouldn't have trailing '/'
            ret += st.top();
            st.pop();
        }
        return ret;
        }
};
