class Solution {
public:
    int is_operator(string s){
      return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int evalRPN(vector<string>& tokens) {
      stack<int> st;

      for(auto &s: tokens){
        
        if(!is_operator(s))  st.push(stoi(s));
        else{
          //Warning: b will appear on top of a since we are using stack
          int b = st.top();
          st.pop();
          int a = st.top();
          st.pop();

          if(s=="+")  st.push(a+b);
          if(s=="-")  st.push(a-b);
          if(s=="*")  st.push(a*b);
          if(s=="/")  st.push(a/b);
        }
      }

      return st.top();
    }
};
