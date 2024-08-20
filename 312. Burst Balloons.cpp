/*
Time: O(n^2)
Space: O(n^2)

DP 
States: Left Boundary, Right Boundary
Similar to Matrix Chain Multiplication

Rather than choosing the pivot element to be popped first,
We will consider the pivot element to be popped first?

Why?

Because if we pop first partitioned index p first, then the subproblems (left,p-1) and (right,p-1) don't stay independent (e.g. fors the left partition, popping the rightmost element will gain a value that is dependant on whichever element is remaining last in right partition)

That's why for each index i = left to right, we will consider i to be popped last

Also note that, for any call with (left,right), we can be sure that left-1 and right+1 is not popped before this call returns (because they were choosen as the pop-last-pivot which resulted in this (left,right) call in the first place)

*/

class Solution {
public:
    vector<int> a;
    vector<vector<int>> dp;

    int call(int left, int right){
        //base cases
        if(left > right)  return 0;
        if(left == right)  return a[left-1] * a[left] * a[left+1];

        if(dp[left][right] != -1)  return dp[left][right];

        //iterate from i = left to right, and consider each i to be bursted last
        int ans = 0;
        for(int i=left;i<=right;i++){
            int score = call(left, i-1) + call(i+1,right) + a[left-1] * a[i] * a[right+1]; //left-1 and right+1 is guaranteed to be remaining
            ans = max(ans, score);
        } 

        return dp[left][right] = ans;
    }



    int maxCoins(vector<int>& nums) {
        
        a.push_back(1);
        for(auto u: nums)  a.push_back(u);
        a.push_back(1); 

        int n = a.size();

        dp = vector(n, vector(n, -1));

        return call(1,a.size()-2);

    }
};
