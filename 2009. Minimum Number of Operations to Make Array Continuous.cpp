/*
O(N) solution
Try to find the range equal to n-1 having the maximum no. of _unique_ elements
Then we can just change the remaning elements' value to fall in that range
*/

class Solution {
public:
    int minOperations(vector<int>& v) {
        unordered_map<int,int> cnt;

        sort(v.begin(),v.end());
        int left=0;

        int n = v.size();
        int maxi = 0;
        int unique = 0;

        for(int i=0;i<n;i++){
          while(left<i && v[i]-v[left] > n-1){  
            int val = v[left];
            cnt[val]--;
            if(cnt[val]==0)  unique --;

            left++;
          }

          int val = v[i];
          if(cnt.count(val)==0) cnt[val] = 0; 
          cnt[val]++;

          if(cnt[val]==1)  unique++;

          
          maxi = max(maxi, unique);
        }

        return n-maxi;
    }
};
