class Solution {
public:
    bool find132pattern(vector<int>& v) {
      int n = v.size();
      vector<int> prev_greater(n, 0);
      vector<int> min_so_far(n, 1e9);
      stack<int> st;

      //build minimum so far found array (min upto i-1th index)
      for(int i=1;i<n;i++){
        min_so_far[i] = min(min_so_far[i-1], v[i-1]);
      }

      //build monotonic stack
      prev_greater[0] = -1;
      for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()] <= v[i]){
          st.pop();
        }

        if(!st.empty())  prev_greater[i] = st.top();
        st.push(i);
      }

      //for each i, lets see if it can be the k
      //i.e. the prev greater index has a min_so_far < v[k]

      for(int i=2;i<n;i++){
      
        int prev_greater_index = prev_greater[i];
        if(prev_greater_index==-1)  continue;
        
        if(min_so_far[prev_greater_index] < v[i])
          return true;
      }

      return false;
    }
};
