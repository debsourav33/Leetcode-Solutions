class Solution {
public:
    string s,t;
    int n1, n2;
    vector<vector<int>> dp;
    vector<vector<vector<int>>> nxt;
    

    int call(int p1, int p2){
      //boundary handled with if-else
      //this is for easy construction of nxt array

      if(n1==p1 && n2 == p2)  return 0;

      auto &mem = dp[p1][p2];
      auto &move = nxt[p1][p2];

      if(mem!=-1)  return mem;

      if(p1<n1 && p2<n2 &&  s[p1]==t[p2]){
        move = {p1+1,p2+1};
        return mem = 1 + call(p1+1,p2+1);
      }

      int opt1 = p1<n1 ? 1 + call(p1+1,p2) : 1e9;
      int opt2 = p2<n2 ? 1 + call(p1,p2+1) : 1e9;

      if(opt1<opt2){
        move = {p1+1,p2};
        return mem = opt1;
      }
      else{
        move = {p1,p2+1};
        return mem = opt2;
      }
    }

    string super = "";

    void print_path(int p1, int p2){
      
      if(p1==n1 && p2 == n2)  return;

      int new_p1 = nxt[p1][p2][0];
      int new_p2 = nxt[p1][p2][1];

      //cout<<new_p1<< " "<<new_p2<<endl; 

      if(new_p1 > p1)  super += s[p1];
      else if(new_p2 > p2)  super += t[p2];

      print_path(new_p1,new_p2);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        s = str1, t = str2;
        n1 = s.length(); n2 = t.length();

        dp= vector(n1+1, vector(n2+1, -1));
        nxt= vector(n1+1, vector(n2+1, vector(2,-1)));

        call(0,0);
        print_path(0,0);

        return super;
    }
};
