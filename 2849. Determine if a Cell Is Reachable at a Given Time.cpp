class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x_diff = abs(sx-fx);
        int y_diff = abs(sy-fy);

        //we can go diagnoally until we reach the minimum of x_diff or y_diff
        //then we can take straight route to destination
        //the diagnoal walk saves us min(x_diff,y_diff) steps
        int steps = x_diff + y_diff - min(x_diff,y_diff); // = max(x_diff,y_diff)

        //edge case
        if(steps == 0 & t == 1)  return false;
          
        //we can just bounce around (going back and forth) the destination
        //(even if the destination is neighbor cell, and we have even t, we can work through it by combination of diagonal and straight step)
        //so as long as we have steps <= t, we are good
        return steps <= t;
    }
};
