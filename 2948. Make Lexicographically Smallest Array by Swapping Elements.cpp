class Solution {
public:

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        //step1. get sorted orders of indices
        vector<int> order;
        for(int i=0;i<n;i++)  order.push_back(i);
        sort(order.begin(), order.end(), [this, &nums](int x, int y) {
            return nums[x] < nums[y];
        });


        //step2. group the indices reachable from one another (i.e., abs diff <= limit)
        vector<vector<int>> groups;

        int last = 0;
        vector<int> g = {order[0]};
        for(int i=1;i<n;i++){
          int pos = order[i];
          int last_pos = order[i-1];
          if(abs(nums[pos] - nums[last_pos]) <= limit)  g.push_back(pos);
          else{
            groups.push_back(g);
            g= {pos};
          }
        }

        if(g.size())  groups.push_back(g);

        
        //step 3. for each group of indices, sort the indices in original nums array (or construc another array, ret)
        vector<int> ret = vector(n,0);

        for(auto g: groups){
          auto tmp = g;
          sort(tmp.begin(),tmp.end());

          for(int i=0;i<tmp.size();i++){
            int pos = tmp[i];
            int val = nums[g[i]];
            ret[pos] = val;
          }
        }

        return ret;
    }
};
