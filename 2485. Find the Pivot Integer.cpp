/*
We can do this in O(logN) using Binary Search on the property of first k numbers summing to k(k+1)/2 .
*/

class Solution {
public:
    int sum_k(int k){
        if(k<=0)  return 0;
        return (k*(k+1))/2;
    }

    int pivotInteger(int n) {
        int lo=1, hi = n;

        while(lo<=hi){ // n = 1, ans is 1
            int mid = (lo+hi)/2;

            int left_part = sum_k(mid);
            int right_part = sum_k(n) - sum_k(mid-1);
            
            if(left_part == right_part)   return mid;
            if(left_part < right_part)   lo = mid+1;
            else  hi = mid-1;
        }

        return -1;
    }
};
