class Solution {
public:
    using ll = long long;
    
    /* Approach #1
     - Determine the longest palindromic prefix using hashing
    Then, we can just add the remaining characters to the begining in reverse order
    */
    int hashing(string &s){
       int ans = 0;
       
       ll mod = 1e9+9;
       ll p = 31;
       ll pow = 1;

       ll h1 = 0, h2 = 0;

       for(int i=0;i<s.length();i++){
         ll val = s[i] - 'a' + 1;
         h1 = (h1 + s[i] * pow) % mod;  //hash
         h2 = (h2 * p + s[i]) % mod; //reverse hash

         if(h1==h2)  ans = i;

         pow = (pow * p) % mod;
       }

       return ans;
    }


    /* Approach #2
    
    Target: finding largest palindromic prefix of s
    Approach:  
      - Reverse s and consider it as text
      - Consider original s as pattern
      - find the highest match involving last character of text
      - this match refers to the largest palindrome
    Then, just append remaining characters of s in the begining in reverse order 
    */
    vector<int> prefix(string& p){
      int n = p.length(), now;
      vector<int> pref(n,-1);

      now = pref[0] = -1;
      for(int i=1;i<n;i++){ //starts from 1
        while(now!=-1 && p[now+1] != p[i])  now = pref[now];

        if(p[now+1] == p[i])  now++;
        pref[i] = now;
      }

      return pref;
    }

    int kmp(string& t, string& p){
      auto pref = prefix(p);
      
      int n = t.length(), now = -1;
      

      for(int i=0;i<n;i++){ //starts from 0
        while(now!=-1 && p[now+1] != t[i])  now = pref[now];

        if(p[now+1] == t[i])  now++;
        if(now == p.length()-1)  return now;
      }

      cout<<now<<endl;
      return now; //now will be minimum of 1 (e.g., match cba -> abc)
    }
    
    string shortestPalindrome(string s) {
      if(s=="")  return s;

      string ret = "";
      string rev = s;
      reverse(rev.begin(),rev.end());
      
      int idx = kmp(rev, s); //or, idx = hashing(s);

      for(int i=s.length()-1;i>idx;i--){
        ret += s[i];
      }

      ret += s;

      return ret;
    }
};
