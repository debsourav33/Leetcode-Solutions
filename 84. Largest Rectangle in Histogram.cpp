class Solution {
public:

    int largestRectangleArea(vector<int>& h) {
      int n = h.size();
      stack<int> st;
      vector<int> prev_smaller(n,-1);
      vector<int> next_smaller(n,n);

      //build monotonic stack
      for(int i=0;i<n;i++){
        while(!st.empty() && h[st.top()] > h[i]){
          next_smaller[st.top()]  = i;
          st.pop();
        }

        if(!st.empty())
          prev_smaller[i] = st.top();

        st.push(i);
      }

      //for(int i=0;i<n;i++)  printf("i=%d, prev=%d, next=%d\n",i,prev_smaller[i],next_smaller[i]);

      int ans = 0;

      //for a index i, the elements between prev_smaller[i] and next_smaller[i] has lengths >= h[i], 
      //so we can take all to build a rectangle
      for(int i=0;i<n;i++){
        int pr = prev_smaller[i];
        int next = next_smaller[i];

        int range = next - pr - 1; //length
        int rect = range * h[i]; //length * width
        ans = max(ans,rect);
      }


      return ans;      
    }
};
