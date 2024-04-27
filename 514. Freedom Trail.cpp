/*
Time: O(r*k*log(r))
Space: O(r*k)

DP approach:
    At any step, let the key to find is 'x', we have the option to choose any occurence index of 'x' in ring
    If we choose any such occurence and make recursive call, the TC will be O(r*k * r) [since, there can be r occurence of a key element]
    but do we really need to consider all occurence?
    we can just consider nearmost left and right occurences!
    afterall, we going further left of nearmost left (or further right of nearmost right) doesn't give us benefit
     - if the next key is to the right of nearmost left, going further left is a loss (we take longer path to go left and to return right)
     - if the next key is to the left of nearmost left, we firs take the shorest path to nearmost left and then continue left, which is equivalent to going further left at first place (so, no gain, no loss)
    hence, we can just consider to go to nearmost left and right
*/

class Solution {
public:

    vector<vector<int>> v;
    string key, ring;

    vector<vector<int>> dp;


    //function that gives us minimum of clockwise and anticlockwise distances
    int dist(int x, int y){
        int n = ring.length();
        int clc_wise = (y - x + n) % n;
        int anti_clc_wise = (x - y + n) % n;

        return min(clc_wise, anti_clc_wise);
    }

    int call(int r, int k){
        if(k == key.length())  return 0;
        if(dp[r][k] != -1)  return dp[r][k];

        auto &ids = v[key[k]-'a'];
        int n = ids.size();

        //binary search to find nearmost right (or equal) occurence index in ring
        int idx = lower_bound(ids.begin(), ids.end(), r) - ids.begin();
        
        //go1 = nearmost left index
        //go2 = nearmost right index
        int go1 = v[key[k]-'a'][idx % n], go2 = v[key[k]-'a'][(idx-1 + n) % n];
        
        return dp[r][k] = 1 + min(dist(r,go1) + call(go1, k+1), dist(r,go2) + call(go2, k+1));

    }

    int findRotateSteps(string ring, string key) {
        this->key = key;
        this->ring = ring;

        //store occurences in sorted order
        v = vector(26, vector<int>());
        dp = vector<vector<int>>(ring.size(), vector<int>(key.size(), -1));

        for(int i=0;i<ring.length();i++){
            auto &c = ring[i];
            v[c-'a'].push_back(i);
        }

        return call(0,0);
    }
};
