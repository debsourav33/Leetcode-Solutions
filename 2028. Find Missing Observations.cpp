/*
Time: O(n)
Space: O(1)


Steps:

1. find how much more we need (to_add) to achieve a total sum = (m+n) * mean
2. if to_add is smaller than n, or greater than n*6 => this is beyond our range, we return {}
3. Otherwise, find the ceiling of (to_add/n), call it ceiled_mean_to_add
4. add ceiled_mean_to_add n times to result
5. How much extra we have added? => extra = ceiled_mean * n - to_add
6. Notice that, extra must be < n (if it was >= n, we would have got a bigger ceiled_mean_to_add)

So, substract 1 from each of the extra elements
*/



class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ret;
        int sum = 0;
        for(auto u: rolls)  sum += u;

        //1. find how much more we need (to_add) to achieve a total sum = (m+n) * mean
        int m = rolls.size(); 
        int expected = (n+m) * mean;
        int to_add = expected - sum;

        //2. if to_add is smaller than n, or greater than n*6 => this is beyond our range, we return {}

        if(to_add < n || to_add > n*6)  return {};

        //Otherwise, find the ceiling of (to_add/n), call it ceiled_mean_to_add
        // add ceiled_mean_to_add n times to result
        
        int add_mean = (to_add-1)/n + 1;
        int extra = add_mean * n - to_add;
        
        for(int i=0;i<n;i++)  ret.push_back(add_mean);

        //How much extra we have added? => extra = ceiled_mean * n - to_add
//So, substract 1 from each of the extra elements
        for(int i=ret.size()-1; i>=ret.size()-extra; i--)  ret[i] -= 1;

        return ret;
    }
};
