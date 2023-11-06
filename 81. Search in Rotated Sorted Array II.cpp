class Solution {
public:
    vector<int> v;
    int n;

    int find_pivot(int lo,int hi){
      while(lo<hi){
        int mid = (lo+hi+1)/2;

        if(v[0] <= v[mid])  lo = mid;
        else  hi = mid-1;
      }

      return lo;
    }

    int bisec(int lo, int hi, int target){
      while(lo<hi){
        int mid = (lo+hi+1)/2;

        if(v[mid] <= target)  lo = mid;
        else  hi = mid - 1;
      }

      //lo can be out of bound
      return lo >= 0 && lo <= n-1 &&  v[lo] == target;
    }

    bool search(vector<int>& nums, int target) {
        v = nums;
        n = nums.size();

        if(v[0]==target)  return true;

        int lo = 0, hi = n-1;

        //remove trailing duplicates
        //this is important to find pivot using bi-search property
        //unfortunately this can be o(n) in worst case, and no trick can save you from this
        while(hi >=0 && v[0] == v[hi])  hi--; 

        int pivot = find_pivot(lo,hi);

        //search in first half until pivot and in last half from pivot
        return bisec(0,pivot,target)  || bisec(pivot+1,hi,target);

    }
};
