class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> open;
        stack<int> close;

        for(int i=0;i<s.length();i++){
          char c = s[i];

          if(c=='(')  open.push(i);
          if(c==')')  close.push(i);

          //whenever there's more ) than (, pop the )
          if(close.size() > open.size()){
            int idx = close.top();
            s[idx] = '-';
            close.pop();
          }
        }

        //make sure equal number of ( and ) exist
        while(open.size() != close.size()){
          int idx = open.top();
          s[idx] = '-';
          open.pop();
        }

        string ret = "";

        for(char c: s){
          if(c!='-'){
            ret += c;
          }
        }

        return ret;
        
    }
};
