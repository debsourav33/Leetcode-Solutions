/*
Time: O(n)
Space: O(1)


Greedy:

If we reformulate the scenario ->

As we traverse from left to right, whatever candidate we considered for the first of the pair gets its value decreased by one for every iteration.

For any index j, if the candidate's value falls below v[i], then v[i] becomes this candidate for the next index (and possible for more index on the right)
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int maxi = v[0];
        int ans = 0;

        for(int i=1;i<v.size();i++){
            maxi--;

            int score = v[i] + maxi;
            ans = max(ans, score);

            //update maxi later -> if we updated earlier, i and j could have been same
            maxi = max(maxi, v[i]);
        }

        return ans;
    }
};
