/*
Time: O(n^3)
Space: O(n^2)

DP (Minimax Algorithm):
States: current pile no, size of m, turn (alice or bob?)

For turn = alice, try to maximize the gain
For turn = bob, try to minimize the gain
*/

class Solution {
public:
    int n;
    vector<int> piles;
    vector<vector<vector<int>>> dp;

    int call(int p, int m, bool turn){
        if(p >= n)  return 0;

        int ans;
        m = min(n, m); //warning: dp table overflow if m is not trimmed inside n

        int &mem = dp[p][m][turn];
        if(mem != -1)  return mem;

        if(!turn){ //alice
            ans = 0;
            int gain = 0;
            for(int i=p;i<min(n, p+2*m);i++){ //take as many piles you want equal or under M piles 
                gain += piles[i];
                int x = i-p+1;
                ans = max(ans, gain + call(i+1, max(m, x) ,1-turn)); //alice tries to maximize her winning!
            }
        } //bob
        else{
            ans = 1e9;
            for(int i=p;i<min(n, p+2*m);i++){ //take as many piles you want equal or under M piles  
                int x = i-p+1;
                ans = min(ans, call(i+1, max(m, x) ,1-turn)); //bob tries to minimize that!
            }
        }

        return mem = ans;
    }

    int stoneGameII(vector<int>& piles) {
        this->piles = piles;
        n = piles.size();

        dp = vector(n, vector(n+1, vector(2, -1)));

        return call(0,1,0);
    }
};
