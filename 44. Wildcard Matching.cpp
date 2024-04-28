/*
Time: O(n)
Space: O(n)

DP
  States: position i in s, position j in p
  1. p[j] = ? , we consider s[i] and p[j] match and call for (i+1, j+1)
  1. p[j] = * , 
    we consider s[i] and p[j] match and call for (i+1, j+1)
    we consider s[i] and p[j] match, but p[j] = * extends, so call for (i+1, j)
    we consider p[j] is empty, so call for (i, j+1)
    
   important:
    if s is fully traversed, check if either 1. the rest of p is empty, or 2. p is traversed  

*/

class Solution {
public:
    string s, p;
    vector<vector<int>> dp;


    bool call(int i, int j){
        //important:
        //if s is traversed, check if either 1. the rest of p is empty, or 2. p is traversed  
        if(i==s.length()){
              for( ; j<p.length();j++)  if(p[j] != '*')  return dp[i][j] = false;
              return dp[i][j] = true; //if p is traversed, then we reach here immidiately
        }
        if(j == p.length())  return dp[i][j] = false; //p is traversed but s is not, return false (s has no wild *)

        if(dp[i][j] != -1)  return dp[i][j];

        if(p[j] == '?')  return dp[i][j] = call(i+1,j+1); //match and take it
        if(p[j] == '*')  return dp[i][j] = call(i+1,j+1) || call(i+1,j) || call(i,j+1); //1. match and take, or 2. match and don't take, or 3. make it empty and dont take
        return dp[i][j] = s[i] == p[j] && call(i+1,j+1); //p[j] is alphanumeric char, so must match and take or return false
    }

    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;

        dp = vector<vector<int>>(s.length()+1, vector<int>(p.length()+1, -1));

        return call(0,0);
    }
};
