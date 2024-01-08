class Solution {
public:
    vector<int> a;
    int n;
    static const int P = 1<<10;

    int dp[10][P][2][2][2];


    int call(int pos, int mask, bool leading_nonzero, bool smaller, bool twice){
      if(pos==n)  return twice;
      
      int &mem = dp[pos][mask][leading_nonzero][smaller][twice];
      if(mem!=-1)  return mem;

      int st = 0;
      int endi = smaller ? 9 : a[pos];
      int ans = 0;

      for(int i=st;i<=endi;i++){
        int curr_mask = mask;
        if(leading_nonzero || i>0)  curr_mask = curr_mask | (1<<i); //set bit only if a non zero digit placed (to prevent setting bit for leading non zeroes)

        ans += call(pos+1,
                    curr_mask,  
                    leading_nonzero || i>0, //check if we placed a non zero digit yet
                    smaller || i < a[pos],
                    twice || (mask & (1<<i)));  //check bit
      }

      return mem = ans;
    }


    int numDupDigitsAtMostN(int num) {
        a.clear();
        memset(dp,-1,sizeof(dp));

        while(num!=0){
          a.push_back(num%10);
          num /= 10;
        }

        n = a.size();
        reverse(a.begin(),a.end());

        return call(0,0,false,false,false); 
    }
};
