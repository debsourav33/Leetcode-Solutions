/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int searchInLeft(MountainArray &mountainArr, int lo, int hi, int target){
      while(lo<hi){
        int mid = (lo+hi)/2;
        int val = mountainArr.get(mid);

        if(val==target)  return mid;

        if(target<val)  hi = mid-1;
        else lo = mid + 1;
      }

      return mountainArr.get(lo) == target ? lo : -1;
    }

    int searchInRight(MountainArray &mountainArr, int lo, int hi, int target){
      while(lo<hi){
        int mid = (lo+hi)/2;
        int val = mountainArr.get(mid);

        if(val==target)  return mid;

        if(target>val)  hi = mid-1;
        else lo = mid + 1;
      }

      return mountainArr.get(lo) == target ? lo : -1;
    }

    int findPivot(MountainArray &mountainArr, int n){
      //pivot index must be < n-1
      int lo=0, hi= n-2;
      while(lo<hi){
        int mid = (lo+hi)/2;

        int val1 = mountainArr.get(mid);
        int val2 = mountainArr.get(mid+1);

        //if value at an index is greater than its next element, we know we are in the right subpart
        if(val1>val2)  hi = mid;
        else lo = mid + 1;
      }

      return lo;
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
       int n = mountainArr.length(); 

       int p = findPivot(mountainArr, n);
       int idx = searchInLeft(mountainArr, 0, p, target);
       if(idx!=-1)  return idx;

       idx = searchInRight(mountainArr, p+1, n-1, target);
       
       return idx;
    }
};
