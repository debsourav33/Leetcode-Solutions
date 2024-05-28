/*
Time: O(n)
Space: O(1)

2 pointer (Squeeze-Window): 
Maintain left and right

Keep adding the cost for right = 0 to n-1 in each iteration
and squeeze window from left as long as the cost exceeds maxCost
If the cost is <= maxCost, then the window is a valid one!
*/

class Solution {
public:
    int solve(string& s, string& t, int maxCost){
        int n = s.length();
        
        int ans = 0;
        int cost = 0;

        int left = 0;
        for(int right=0; right<n; right++){ 
            cost += abs(s[right] - t[right]);

            while(cost > maxCost){ //we have to squeeze window from left as long as the cost exceeds maxCost
                cost -= abs(s[left] - t[left]);
                left++;    
            }

            ans = max(ans, right-left+1);
        }
        

        return ans;
    }

    int equalSubstring(string s, string t, int maxCost) {
        return solve(s,t,maxCost);
    }
};