/*
1. Sort the st, endi, profit arrays on the order of start time
2. Do DP. 
  State: Current Position
  Two options
  1. Don't do this activity and move to next one
  2. Do this activity (and gain profit) amd move to the one that has the earliest start time >= current activity's end time (use binary search to find it)
*/

class Solution {
public:
    int n;
    vector<int> st, endi, profit;
    vector<int> order;
    vector<int> dp;

    int get_pos(int val){
      int lo = 0, hi = n-1;

      while(lo<hi){
        int mid = (lo+hi)/2;
        if(st[mid] >= val)  hi = mid;
        else  lo = mid+1;
      }

      return st[lo] >= val ? lo : n;
    }

    int call(int p){
      if(p==n)  return 0;
      if(dp[p]!=-1)  return dp[p];

      int op1 = call(p+1);
      int op2 = profit[p] + call(get_pos(endi[p]));

      return dp[p] = max(op1,op2);
    }

    int jobScheduling(vector<int>& st, vector<int>& endi, vector<int>& profit) {
      this->n = st.size();
      this->st = st;
      dp = vector(n,-1);

      for(int i=0;i<n;i++)  order.push_back(i);
      sort(order.begin(),order.end(), [this](int a, int b){
        return this->st[a] < this->st[b];
      });

      this->endi = vector(n,0);
      this->profit = vector(n,0);

      for(int i=0;i<n;i++){
        int pos = order[i];
        this->endi[i] = endi[pos];
        this->profit[i] = profit[pos];
      }

      sort(this->st.begin(),this->st.end());

      for(int i=0;i<n;i++){
        //cout<<this->st[i]<<" "<<this->endi[i]<<" "<<this->profit[i]<<endl;
      }

      return call(0);

    }
};
