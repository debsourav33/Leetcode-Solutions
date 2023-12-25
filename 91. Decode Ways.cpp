class Solution {
public:
    
    vector<int> dp;

    int call(int pos, string &s){
      if(pos == s.length())  return 1;
      
      //0 doesn't map to any char and we can't have leading zeros
      if(s[pos]=='0')  return 0;

      if(dp[pos]!=-1)  return dp[pos];

      //opt1: take only 1 digit
      int ans = call(pos+1, s);

      //opt2: try to take 2 digits (<= 26 and without leading zero)
      if(pos<s.length()-1){
        int val = (s[pos] - '0') * 10 + (s[pos+1] - '0');

        if(val<=26)  ans += call(pos+2,s);
      }

      return dp[pos] = ans;
    }

    int numDecodings(string s) {
      dp = vector(s.length(),-1);

      return call(0,s);
    }
};
