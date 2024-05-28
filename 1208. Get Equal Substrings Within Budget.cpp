/*
Time: O(n)
Space: O(1)

2 pointer (Expand-Window): 
Maintain left and right

Try to expand right as long as the elements inside (left to right) boundary has exchange cost <= maxCost
When we update left, remove the cost associated with prev left
*/

class Solution {
public:
    int solve(string& s, string& t, int maxCost){
        int n = s.length();
        
        int ans = 0;
        int cost = 0;

        int right = 0;
        for(int left=0; left<n; left++){ //left is only for removal, right for expansion

            while(right<n && cost <= maxCost){ //as long as the cost doesn't exceed maxCost
                cost += abs(s[right] - t[right]);
                right++;

                if(cost <= maxCost){ //if the cost in this boundary still inside maxCost
                    ans = max(ans, right-left);
                }
                else{
                    break;
                }
            }

            cost -= abs(s[left] - t[left]); //before next iteration, remove the cost associated with current left
        }
        

        return ans;
    }

    int equalSubstring(string s, string t, int maxCost) {
        return solve(s,t,maxCost);
    }
};
