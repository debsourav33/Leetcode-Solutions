class Solution {
public:
    vector<int> wts;
    int days;

    int can(int maxw){
      int d = 1, load = 0;
      for(auto w: wts){
        if(w>maxw)  return false;

        load += w;

        if(load>maxw){
          d++;
          load = w;
        }  
      }

      return d <= days;
    }

    int shipWithinDays(vector<int>& w, int d) {
      wts = w;
      days = d;

      int lo = 1, hi = 5*10e6;

      while(lo<hi){
        int mid = (lo+hi)/2;
        if(can(mid))  hi = mid;
        else lo = mid+1;
      }    

      return lo;
    }
};
