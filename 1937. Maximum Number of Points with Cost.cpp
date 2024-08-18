/*
Time: O(n^2)
Space: O(n^2)

This is a development from '1014. Best Sightseeing Pair'

Greedy + DP
- Similar to 1014, for each row, from col = 0 to row.size()-1, we try to find best value for this col, which can be this col's value or a col from its left or right (the distance gets decreased from its value if it's on left or right) 
- Then we just jump from each col in this row to the same column in the below row (this is because we already calculated the best value gainable for each col of current row, so for the same column in below row we don't need to look for other cols)
*/


class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>> p;
        
        for(auto &v: points){
            vector<long long> tmp;
            for(auto &u: v)  tmp.push_back(u);
            p.push_back(tmp);
        }

        for(int i=1;i<p.size();i++){
            vector<long long>& row = p[i-1];

            //Similar to 1014, from col = 0 to row.size()-1, we try to find best value for this col
            //traversing left to right to see if any element from left of each column might gain greater value 
            long long maxi = row[0];
            for(int c=1;c<row.size();c++){
                maxi--; //value its decremented for every position to the right
                maxi = max(maxi, row[c]);
                row[c] = maxi;
            }

            //traversing right to left to see if any element from right of each column might gain greater value
            maxi = row[row.size()-1];
            for(int c=row.size()-2;c>=0;c--){
                maxi--; //value its decremented for every position to the right
                maxi = max(maxi, row[c]);
                row[c] = maxi;
            }

            vector<long long>& curr_row = p[i];
            for(int c=0;c<curr_row.size();c++){
                curr_row[c] += row[c]; //add points from same column, upper row
            }
        }

        long long ans = 0;
        vector<long long>& last_row = p[p.size()-1];

        //find the biggest value from right row -> this is where we will end her point collecting
        for(int c=0;c<last_row.size();c++)  ans = max(ans, last_row[c]);

        return ans;
    }
};
