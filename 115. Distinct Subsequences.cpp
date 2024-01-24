class Solution {
public:
    string s, t;
    int n, m;
    map<char, vector<int>> ind;
    vector<vector<int>> dp;

    int call(int s_pos, int t_pos){
      if(t_pos==n)  return 1;
      if(s_pos==m)  return 0;

      //This optimization is needed to beat TLE
      if(n - t_pos > m - s_pos)  return 0;

      char c = t[t_pos];

      int &mem = dp[s_pos][t_pos];
      if(mem!=-1)  return mem;

      mem = 0;
      
      //binary search to find the next occurance of c in s
      if(ind.count(c)==0)  return 0;
      int nxt_pos = lower_bound(ind[c].begin(),ind[c].end(),s_pos) - ind[c].begin();

      //for all next occurences of c, make a recursive call 
      
      for(int i=nxt_pos;i<ind[c].size();i++){
        //cout <<c<<" "<< ind[c][i] << endl;
        mem += call(ind[c][i]+1, t_pos+1);
      }
      

      return mem;
    }

    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;

        m = s.length();
        n = t.length();

        dp = vector(m, vector(n,-1));

        //store all indices of each character in sorted manner
        for(int i=0;i<m;i++){
          char c = s[i];
          
          if(ind.count(c)==0)  ind[c] = {};
          ind[c].push_back(i);
        }


        return call(0,0);
    }
};
