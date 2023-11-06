class Solution {
public:
    string s, p;

    void preprocess(){
      string p_mod = "";

      for(int i=1;i<p.length();i++)
        if(p[i]=='*'){
          if(p[i-1]=='*')  continue;

          if(p[i-1]=='.')  p_mod += '!';
          else   p_mod += (p[i-1] - 32); //capitalize
        }
        else if(p[i-1]!='*'){
          p_mod += p[i-1];
        }

        if(p[p.length()-1]!='*')  p_mod += p[p.length()-1];
        p = p_mod;
    }

    bool isCapital(char c){
      return c >= 'A' && c <= 'Z';
    }

    char lower(char c){
      return c + 32;
    }

    vector<vector<int>> dp;

    bool allCapital(string p, int st, int endi){
      for(int i=st;i<=endi;i++)  
        if(!isCapital(p[i]) && p[i]!='!')  return false;
      return true;
    }

    bool call(int p1, int p2){
      if(p1 == s.length() && p2 == p.length())  return true;
      if(p2 == p.length())  return false;
      if(p1 == s.length())  return allCapital(p,p2,p.length()-1);  //we can discard the trailing *s

      int &mem = dp[p1][p2]; 
      if(mem!=-1)  return mem;

      if(p[p2]=='.' || s[p1]==p[p2])  return mem = call(p1+1,p2+1);
      else if(isCapital(p[p2])){
        bool ans = call(p1, p2+1);  //repeat 0 times

        if(lower(p[p2]) == s[p1])  ans = ans || call(p1+1,p2) || call(p1+1,p2+1);  //repeat one time
        return mem = ans;
      }
      else if(p[p2]=='!')
        return mem = call(p1,p2+1) || call(p1+1,p2) || call(p1+1,p2+1);  //repeat 0 or 1 time  

      return mem = false; //concrete characters, don't match
    }

    bool isMatch(string s, string p) {
      int n1 = s.length();
      int n2 = p.length();
      dp = vector(n1, vector(n2,-1));

      this->s = s;
      this->p = p;    

      preprocess();

      cout<<this->s<<endl;
      cout<<this->p<<endl;

      return call(0,0);
    }
};
