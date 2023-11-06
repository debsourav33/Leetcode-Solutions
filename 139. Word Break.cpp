class Solution {
public:
    unordered_map<string,bool> m;

    vector<vector<int>> dp;
    string s;
    int n;

    //dp states - st : starting index of current substring, curr = ending index of current substring
    bool call(int st, int curr, string t){
      if(curr==n)  return m.count(t);
      
      int &mem = dp[st][curr];
      if(mem!=-1)  return mem;

      bool ans = call(st,curr+1,t+s[curr]);

      if(m.count(t))  ans = ans || call(curr,curr+1, string(1,s[curr]));

      return mem = ans;
    }

    bool wordBreak(string s, vector<string>& words) {
        this->s = s;
        n = s.length();

        dp = vector(n, vector(n,-1));
        
        m.clear();
        for(auto word: words)  m[word] = true;


        return call(0,0,"");
    }
};
