/*
Approach:

1. Sort using end time
2. Traverse the interval array
    - if overlap found with the previous right boundary, remove current interval (as it has bigger end time and can potentially cause more overlaps)
    - if no overlap found, we take this interval (its end becomes the right)
*/

class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
      return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        
        int cnt = 0;
        vector<int> prev = intervals[0];
        for(int i=1;i<n;i++){
          auto curr = intervals[i];
          if(curr[0] < prev[1])  cnt++; //current interval's start time is before prev's end time -> overlap found!
          else{
            prev = curr; //otherwise, keep it and update prev
          }


        }

        return cnt;
    }
};
