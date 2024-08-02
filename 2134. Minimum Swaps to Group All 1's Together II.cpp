/*
Time: O(n)
Space: O(n)

Sliding Window
Find the window with the minimum no. of zeros in that window, we can just swap them to make all contiguous ones

Note: Window can be circular
*/

class Solution {
public:

    int minSwaps(vector<int>& v) {
        int ones = 0, n = v.size();
        for(auto &u: v)  ones += u; 

        int zeros = 0;
        for(int i=0;i<ones;i++)  zeros += 1 - v[i]; //

        int ans = zeros;

        //Window can be circular
        for(int i=ones;i<n+ones;i++){
            zeros += (1 - v[i%n]); // mod means circular wrap
            zeros -= (1 - v[i-ones]); 

            //
            ans = min(ans, zeros);
        }

        return ans;
    }
};
