//runtime o(n^2)

class Solution {
public:
    int isPali[1005][1005];
    string s;

    //this has a state of i*j, so takes o(n^2) to populate isPali[][] table and once populated it will return in constant time
    bool isPalindrome(int i, int j){
      if(i>=j)  return true;
      if(isPali[i][j]!=-1)  return isPali[i][j];
      
      return isPali[i][j] = s[i]==s[j] && isPalindrome(i+1,j-1);
    }
    
    string longestPalindrome(string str) {
       memset(isPali,-1,sizeof(isPali));  

       s = str;      
       int n = s.length();

       
       int st=0, endi=0;
       int sz=1;

       //iterate from the biggest size and return when palindrome is found
       
       for(int sz=n;sz>=1;sz--){
         for(int i=0;i<=n-sz;i++){
           if(isPalindrome(i,i+sz-1)){ //this has independent total runtime of o(n^2)
             st = i, endi = i+sz-1;
             
             int pal_len = endi-st+1;
             return s.substr(st,pal_len);
           }
         }
       } 

       //cout<<st<<" "<<endi<<endl;

       int pal_len = endi-st+1;
       return s.substr(st,pal_len);
       


    }
};
