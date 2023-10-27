class Solution {
public:
    const int mod = 1000000007;
    int n;
    vector<int> v;
    map<int,int> m;
    map<int,int> dp;


    int howMany(int root){
      if(dp.count(root))  return dp[root]; //no need to calculate same subtree twice

      int idx = m[root];
      long long total = 0;

      for(int i=idx;i>=0;i--){
        int l_val = v[i];
        if(root%l_val != 0)  continue;

        int r_val = root / l_val;
        if(m.count(r_val) == 0)  continue;

        long long left = howMany(l_val);
        long long right = howMany(r_val);

        total += (left * right) % mod; //for every possible combination of left subtree, we can have all possible combination of right subtree to form the actual tree -> so multiply left and right subtree size
        total %= mod;
      }

      return dp[root] = 1 + total; //1 because without having any left/right children, it can be a valid tree!
    }

    int numFactoredBinaryTrees(vector<int>& _v) {
        v = _v;
        n = v.size();
        sort(v.begin(),v.end());

        m.clear();
        dp.clear();

        for(int i=0; i<n;i++){
          m[v[i]] = i;  //map value to index
        }

        long long ans = 0;

        for(int u: v){
          ans += howMany(u);
          ans %= mod;
        }

        return ans;  
    } 
};
