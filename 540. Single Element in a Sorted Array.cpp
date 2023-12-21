class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int lo = 0, hi = n-1;

        //As long as we have got pairs of numbers
        //if index is odd, left side element is same
        //if index is even, right side element is same
        //when it is not true
        //we know we have a singular element in the left

        //edge case, mid = n-1 is prevented because floor (lo+hi)/2 can't be n-1 unless lo==hi
        while(lo<hi){
          int mid = (lo+hi)/2;

          if(mid%2==1 && v[mid]==v[mid-1])  lo = mid+1;
          else if(mid%2==0 && v[mid]==v[mid+1])  lo = mid+1;
          else  hi = mid;
        }

        return v[lo];
    }
};
