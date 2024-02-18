/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */

    //Approach: find the maximum no. of meetings that overlap in any particular time
    int minMeetingRooms(vector<Interval> &intervals) {
         
        int i = 0;
        int ans = 1;

        //sort using end time
        //so that we don't have to worry about if end time for i is bigger or smaller than end time for j
        sort(intervals.begin(), intervals.end(), [&](Interval a, Interval b){
            return a.end < b.end;
        });

        //for every meeting
        while(i<intervals.size()){
            int room = 1;
            int j;

            //check how many meetings overlap in time
            //Important: do not break if you find a non-overlap, continue checking, since there can be overlaps later (the start times are not in sorted order)
            for(j=i+1; j<intervals.size();j++){
                if(intervals[j].start < intervals[i].end)
                    room++;
            }

            ans = max(room, ans);
            i = i+1;
        }


        return ans;
    }
};
