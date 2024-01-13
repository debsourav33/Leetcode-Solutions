class Solution {
public:
    int cnt[2][26];
   
    int minSteps(string s, string t) {
        memset(cnt, 0, sizeof(cnt));
       
        for(char c: s)  cnt[0][c-'a']++;
        for(char c: t)  cnt[1][c-'a']++;

        //those characters that are more in either string has to be altered
        int more = 0;
        for(int i=0;i<26;i++){
          if(cnt[0][i] > cnt[1][i])  
            more += cnt[0][i] - cnt[1][i];
        }

        return more;
    }
};
