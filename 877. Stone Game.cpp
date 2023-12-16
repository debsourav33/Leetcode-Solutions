class Solution {
public:
    vector<int> piles;
    vector<vector<vector<int>>> dp;
    
    //this function will return the best difference of piles for either player
    //for Alice (turn == 0), best is the positive maximum difference
    //for Bob (turn == 1), best is a negative minimum difference
    int call(int i, int j, int turn){
      if(i>j)  return 0;

      int &mem = dp[i][j][turn];
      if (mem!=-1)  return mem;

      if(turn==0){ //alice -> try to maximize difference
        return mem = max(piles[i] + call(i+1,j,1),  piles[j] + call(i,j-1,1));
      }
      else{ //bob -> try to minimize difference
        return mem = min(-piles[i] + call(i+1,j,0),  -piles[j] + call(i,j-1,0));
      }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp = vector(n,vector(n,vector(2,-1)));

        this->piles = piles;
        int alice_max = call(0,n-1,0);
        cout<<alice_max<<endl;
        return alice_max > 0;
    }
};
