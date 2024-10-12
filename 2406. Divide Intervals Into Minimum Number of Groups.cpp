/*
Time: O(nlogn)
Space: O(n)

Similar to Meeting Room II
- Sort intervals based on start time
- Maintain a pq (min-heap) of interval end time. Treverse the intervals one by one. When traversing, keep popping the pq until it's empty or the top has a value greater than the current interval's start time (means all remaining pq intervals overlap). Then push the interval end time to the pq.
- Track the maximum size the pq gets in any iteration. This refers to the min no. of groups we need the intervals to split into.
*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());

        auto cmp = [](int a, int b){
            return a > b;
        };


        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for(auto &v: intervals){
            //keep popping the pq until it's empty or the top has a value greater than the current interval's start time (means all remaining pq intervals overlap)
            while(!pq.empty() && pq.top() < v[0]){
                pq.pop();
            }

            pq.push(v[1]);

            //Track the maximum size the pq gets in any iteration. This refers to the min no. of groups we need the intervals to split into.
            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};
