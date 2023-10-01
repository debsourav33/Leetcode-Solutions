class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> next_greater(t.size(),0);
        vector<int> ret(t.size(),0);
        stack<int> st;

        //implement monotonic stack
        for(int i=0;i<t.size();i++){
          int val = t[i];
         
          while(!st.empty() && t[st.top()] < val){
            next_greater[st.top()] = i;
            st.pop();
          }

          st.push(i);
        }

        //left overs
        while(!st.empty()){
            next_greater[st.top()] = 0;
            st.pop();
          }

        for(int i=0;i<t.size();i++){
          if(next_greater[i]==0)
            ret[i] = 0; 
          else
            ret[i] = next_greater[i] - i;
        }

        return ret;

    }
};
