class Solution {
public:
    /*
    Approach (Robin Carp)
    
    Solve using hash rolling

    h2 = p^2 * s[0] + p * s[1] + s[2]
    h3 = p^2 * s[1] + p * s[2] + s[3]

    hk = (h(k-1) - p^(len-1) * s[k-len]) * p + s[k]
    */

    using ll = long long;
        
    ll p = 31, mod = 1e15+9;
    vector<ll> pows;
    
    void pre(int n){
      pows = vector<ll>(n,1L);
      pows[0] = 1;

      for(int i=1;i<n;i++){
        pows[i] = (pows[i-1] * p) % mod;
      }
    }

    
    //abc
    int can(string& s, int len){
      unordered_map<ll,int> m;

      ll hash = 0;
      for(int i=0;i<len;i++){
        hash = (hash * p) + s[i];
        hash %= mod;
      }

      m[hash] = 0;
      //cout<<s.substr(0, len)<<" "<<hash<<endl;

      for(int i=len;i<s.length();i++){
        hash = (hash- (s[i-len] * pows[len-1]) % mod) % mod; //subtract (i-len)th char
        hash = (hash + mod) % mod;  //handle negative
        hash = (hash * p) % mod;  //multiply by p
        hash = (hash + s[i]) % mod;  //add ith char

        int sub_start =  i - len + 1; //starting index of this substring
        
        //cout<<sub_start<<endl;
        //cout<<"- "<<s.substr(sub_start, len)<<" "<<hash<<endl;
        
        if(m.count(hash))  return sub_start;
        m[hash] = sub_start; 
      }

      return -1;      
    }

    

    string longestDupSubstring(string s) {
      pre(s.length());


      string ret = "";
      int lo = 0, hi = s.length()-1;
      while(lo<hi){
        int mid = (lo+hi+1)/2;

        int pos = can(s, mid);
        if(pos != -1){
          lo = mid;
          ret = s.substr(pos, mid);
        }
        else{
          hi = mid-1;
        }
      }

      return ret;
    }
};
