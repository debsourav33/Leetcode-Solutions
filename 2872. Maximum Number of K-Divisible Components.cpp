/*
Time: O(V+E)
Space: O(E)

Whenever a subtree has a sum divisible by k, we can make it a separate component (since the whole tree's sum is divisible by k, if we separate this component for, the remaining sum will still be divisible by k)
*/

class Solution {
public:
    typedef long long ll;
    
    vector<vector<int>> v;
    vector<int> values;
    int k, ans;

    int dfs(int u, int p){
        int sum = values[u];

        for(int adj: v[u]){
            if(adj == p)  continue;

            sum += dfs(adj, u);
            sum %= k; //we care about the divisibility by k, not the real value of sum
        }

        if(sum % k == 0)  ans++; //Whenever a subtree has a sum divisible by k, we can make it a separate component
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->values = values;
        this->k = k;
        ans = 0;

        v = vector(n, vector<int>());

        for(auto &e: edges){
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }        

        dfs(0,-1);
        return ans;


    }
};
