/*
Time: O(n + maxValue)
Space: O(n)

Line Sweep:

Sort the array first,

Then each element e can be seen as an interval of (e-k, e+k)

At each point from minval to maxval (of the intervals of the array), increment in count when we find a starting interval and increment out count when we find an ending interval.

The maximum difference of in and out (in - out) at any point in the range is the maximum overlap area, so that max difference is the answer
*/


class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        int maxi = 0, mini = 1e9;
        unordered_map<int,int> in, out;

        for(auto u: v){
            in[u-k]++;
            out[u+k]++;

            mini = min(mini, u-k);
            maxi = max(maxi, u+k);
        }

        int curr = 0, ans = 0;
        for(int i=mini;i<=maxi;i++){

            //fix: first add in count and then update the answer, because of testcase like [1000], 0 (we can take 1000 first and have an answer of 1)
            curr += in[i];
            ans = max(ans, curr); //The maximum difference of in and out (in - out) at any point in the range is the maximum overlap area, so that max difference is the answer
            curr -= out[i];
        }

        return ans;
    }
};
