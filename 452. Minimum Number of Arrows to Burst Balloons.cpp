/*
Time: O(nlogn)
Space: O(n)

The problem can be formulated as finding the no. of non-overlaping sets of intervals
*/


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<int, vector<int>, greater<int>> q;

        //min heap to store the smallest right boundary of the point in a group
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        int ans = 1;
        q.push(points[0][1]);

        for(int i=1;i<points.size();i++){
            auto &p = points[i];
            int top = q.top();
            
            //if current point exceeds the smallest right boundary (means no overlap with at least one point), we have to start a new set
            //if not, we found overlap with (all elements in) the current set we continue with current set
            if(top < p[0]){  
                ans++;

                //to start a new set, we first have to remove the previous overlapping set of points
                //and the current set initiates to empty
                while(!q.empty())  q.pop();
                
            }
            
            //add the new point to the current set
            q.push(p[1]);
        }

        return ans;
    }
};
