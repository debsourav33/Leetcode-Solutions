class Solution {
public:
    vector<vector<int>> dp;
    int k, n;

    //fill the dp table
    //how many sequences we can make from position pos and having used numbers in mask already?
    //we will use the information to count up to the kth element
    int call(int pos, int mask){
      if(pos==n)  return 1;
      int &mem = dp[pos][mask];
      if(mem!=-1)  return mem;

      int cnt = 0;

      for(int i=1;i<=n;i++){
        if(mask & (1<<i))  continue; //already picked

        cnt += call(pos+1, mask | (1<<i));
      }

      return mem = cnt;
    }

    string solve(){
      string ans = "";
      int pos = 0, prev = 0, mask = 0;

      while(pos<n){
        for(int i=1;i<=n;i++){
          if(mask & (1<<i))  continue; //already picked

          /*
          dp[pos+1][mask | 1<<i] means we took the ith element at position pos and moved to pos+1 (also checking bit in mask)
          */
          int total = prev + dp[pos+1][mask | 1<<i];
          
          //if total (counts found so far + counts with placing i at pos) reaches or exceeds k, we know the sequence starts with the prefix founded so far appended by i and we can move to pos+1
          if(total >= k){
            ans += (char)('0'+i);
            mask = mask | 1<<i;
            break;
          }
          else{
            //otherwise, add up the counts we have found so far
            prev += dp[pos+1][mask | 1<<i];
          }
        }

        pos++;
      }

      return ans;
    }

    string getPermutation(int n, int k) {
        this->n = n;
        this->k = k;

        int mask_size = 1<<(n+1);
        dp = vector(n+1, vector(mask_size, -1));
        
        //this will make things easy
        //when we place anything on the (n-1)th position and move to nth position,
        //it means we got `1` count
        for(int i=0;i<mask_size;i++){
          dp[n][i] = 1;
        }

        call(0,0);

        cout<<dp[0][0]<<endl;
        return solve();
    }
};
