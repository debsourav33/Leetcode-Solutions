class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)  return 0;

        int vis[n];
        unordered_map<int,int> m; //holds the index of a value

        memset(vis,0,sizeof(vis));

        for(int i=0;i<n;i++){
          int val = nums[i];
          m[val] = i; 
        }

        int ans = 0;

        for(int i=0;i<n;i++){
          if(vis[i])  continue;
          
          vis[i] = 1;
          int cnt = 1;

          int val = nums[i];
          
          //check lower reach until m doesn't contain a consecutive value
          //still o(n) since we are tracking the visited indices and don't visit them again
          for(int i=val-1;m.count(i);i--){
            cnt++;
            int idx = m[i];
            vis[m[i]] = 1; //make this index visit
          }

          //check upper reach 
          for(int i=val+1;m.count(i);i++){
            cnt++;
            int idx = m[i];
            vis[m[i]] = 1; //make this index visit
          }

          ans = max(ans,cnt);
        }

        return ans;
    }
};
