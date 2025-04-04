/*
Time: O(logn)  [ O(n) constructor call]
Space: O(1)

Calculate prefix sum that represents the range of each wait
Generate a random number between 1 and highest prefix sum
And Binary search to find out the in which prefix sum range the random value resides in

*/


class Solution {
public:
    vector<int> w;
    vector<int> pre;
    int n;

    Solution(vector<int>& w) {
        this->w = w;
        n = w.size();

        // prefix sum calc
        pre = vector(n, w[0]);

        for(int i=1;i<w.size();i++){
            pre[i] = pre[i-1] + w[i];
        }
    }
    
    // o(logn)
    int pickIndex() {
        // random number between 1 to highest prefix sum
        int maxi = pre[pre.size()-1];
        int rval = (rand() % maxi) + 1; // (1,maxi)

        //Binary search to find out the in which prefix sum range the random value resides in
        int idx = lower_bound(pre.begin(), pre.end(), rval) - pre.begin(); // first idx >= rval

        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
