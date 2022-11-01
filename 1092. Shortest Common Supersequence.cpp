class Solution {
public:
    string s, t;
    int n1, n2;
    int dp[1001][1001];
    pair<int,int> nxt[1003][1003];

    int call(int p1, int p2){
        if(p1==n1 && p2==n2)  return 0;
        if(dp[p1][p2]!=-1)  return dp[p1][p2];

        if(p1==n1){
            nxt[p1][p2] = make_pair(p1,p2+1);
            return dp[p1][p2] = 1+call(p1,p2+1);
        }
        if(p2==n2){
            nxt[p1][p2] = make_pair(p1+1,p2);
            return dp[p1][p2] = 1+call(p1+1,p2);
        }

        if(s[p1]==t[p2]){
            nxt[p1][p2] = make_pair(p1+1,p2+1);
            return dp[p1][p2] = call(p1+1,p2+1) + 1;
        }

        int v1 = call(p1+1,p2), v2= call(p1, p2+1);

        if(v1<v2){
            nxt[p1][p2] = make_pair(p1+1,p2);
        }
        else{
            nxt[p1][p2] = make_pair(p1,p2+1);
        }
        return dp[p1][p2] = 1 + min(v1,v2);
    }

    string construct(int p1, int p2, string res=""){
        if(nxt[p1][p2]==make_pair(-1,-1)){
            return res;
        }

        pair<int,int> p = nxt[p1][p2];
        if(p.first!=p1)  res += s[p1];
        else  res+= t[p2];

        return construct(p.first,p.second,res);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<1002;i++){
            for(int j=0;j<1002;j++){
                nxt[i][j] = make_pair(-1,-1);
            }
        }
        s = str1, t = str2;
        n1 = s.length();
        n2 = t.length();

        cout << call(0,0) <<endl;
        return construct(0,0);
    }
};
