class Solution {
public:
    //build kmp table
    //and return table[n-1]
    int prefix(string& s){
      vector<int> pref(s.length(),-1);
      int now;

      now = pref[0] = -1;

      for(int i=1;i<s.length();i++){
        while(now!=-1 && s[now+1] != s[i])  now = pref[now];
        if(s[now+1] == s[i])  now++;

        pref[i] = now;
      }

      return now;
    }

    //only the substring after the longest matched prefix can be copied to create original string 
    bool repeatedSubstringPattern(string s) {
      int n = s.length();
      int now = prefix(s);
      if(now==-1)  return false;

      int copy_len = n-1-now;
      
      if(n%copy_len)  return false;

      //modding and coming back to 0th index is equivalent to append multiple copies
      for(int i=0,j=0; i<n; i++, j=(j+1)%copy_len){
        if(s[i]!=s[j])  return false;
      }

      return true;

    }
};
