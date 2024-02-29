/*
TC: O(N)
SC: O(N)

Whenever you have the option, try to make leading elements smaller
Maintain a stack (starting from leading element) and while the current element is smaller than the top of stack, pop stack (remove digit) 
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret = "";
        stack<char> st;

        for(auto c: num){
            while(k && !st.empty() && c < st.top()){
                st.pop();  //pop as long as bigger element found on stack -> this helps getting smaller element to the leading positions
                k--;
            }

            st.push(c);
        }

        //pop anymore removable digits
        while(!st.empty() && k--)  st.pop();

        while(!st.empty()){
            ret += st.top();
            st.pop();
        }

        reverse(ret.begin(), ret.end());
        //cout<<ret<<endl;

        //remove leading zeroes
        int start = 0;
        for(int i=0;i<ret.length() && ret[i]=='0';i++){
            start = i+1;
        }

        if(start >= ret.length())  return "0";
        string ans = ret.substr(start,ret.length()-start);


        if(ans.length()==0)  return "0";
        return ans;


    }
};
