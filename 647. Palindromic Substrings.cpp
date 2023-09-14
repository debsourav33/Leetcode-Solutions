class Solution {
public:
    int countSubstrings(string s) {
        int dp[1002][1002];
        int n = s.length();
        int cnt = 0;
        
        memset(dp,0,sizeof(dp));

        //populate dp table for 1 and 2 length palindromes
        for(int i=0;i<n;i++)  dp[i][i] = 1, cnt++;
        for(int i=0;i<n-1;i++){
          dp[i][i+1] = s[i]==s[i+1];
          cnt += dp[i][i+1];
        }

        //now, k (>2) sized palindromes can be found using (k-2) sized palindromes
        for(int k=2;k<n;k++){
          for(int i=0;i<n-k;i++){
            dp[i][i+k] = s[i] == s[i+k] && dp[i+1][i+k-1];
            cnt += dp[i][i+k];
          }
        }

        return cnt;

    }
};
