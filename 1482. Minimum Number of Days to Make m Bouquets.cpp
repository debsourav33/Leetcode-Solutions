/*
TC: O(NLog(Max(Bloom))
SC: O(N)

Binary search over maximum value in bloom array and check how less we can get away with
*/

class Solution {
public:

    //funtion that takes an x number of days and checks if we can make m boutiques in x days
    bool can(int x, vector<int>& bloom, int m, int k){
        vector<bool> v;
        for(auto d: bloom){
            v.push_back(x >= d);
            //cout<<v[v.size()-1]<<" ";
        } 
        cout<<endl;

        int streak = 0;

        for(auto val: v){
            if(val)  streak++;
            else  streak = 0; //reset streak

            if(streak == k){ //a boutique constructed!
                m--; //one less boutique is needed
                streak = 0; //reset streak

                if(m == 0)  return true; //all boutiques done!
            }
        }

        return false;
    }

    int minDays(vector<int>& bloom, int m, int k) {
        int maxi = 1;
        for(auto d: bloom)  maxi = max(maxi, d);

        //corner case
        //if flowers available < no. of flowers needed 
        // WARNING Overflow: if(bloom.size() < m*k)  return -1;
        if(bloom.size()/k < m)  return -1;

        //binary search
        int lo = 1, hi = maxi+1;

        while(lo<hi){
            int mid = lo + (hi-lo)/2;

            if(can(mid, bloom, m, k))
            {
                //cout<<mid<<endl;
                hi = mid;
            }
            else  lo = mid+1;
        }

        //if(lo == maxi+1)  return -1;
        return lo;
    }
};
