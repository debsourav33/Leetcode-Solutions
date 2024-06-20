/*
TC: O(NlogC) (C = max value in pos array)
SC: O(1)
*/

class Solution {
public:
    //function that takes an integer k and returns if its possible to place m balls in minimum k-length gaps
    bool can(vector<int>& pos, int m, int k){
        int last = pos[0]; //always place first ball to first position
        m--;

        for(int i=1;i<pos.size();i++){
            if(pos[i] - last >= k){ //if current position is >= k than last assigned position, greedily assign one more ball to current position
                last = pos[i]; //update last assigned position
                m--; //one less ball need to be assigned

                if(m == 0)  return true; //all balls assigned
            }
        }

        return false;
    }

    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin(), pos.end());

        //difference between first position and last position
        //the answer will be in that range
        int diff = pos[n-1] - pos[0];

        //binary search over this range
        int lo = 0, hi = diff;      
        while(lo<hi){
            int mid = lo + (hi-lo+1)/2; // (lo + hi)/2 can cause overflow

            if(can(pos, m, mid))  lo = mid; //its possible to place m balls in minimum mid-length gaps 
            else  hi = mid-1;
        }

        return lo;
    }
};
