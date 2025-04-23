/*

T: O(nlogn)
S: O(n)

It appears the best way to build an increasing subsequence is: for each element num, if num is greater than the largest element in our subsequence, then add it to the subsequence. Otherwise, perform a linear scan through the subsequence starting from the smallest element and replace the first element that is greater than or equal to num with num. This opens the door for elements that are greater than num but less than the element replaced to be included in the sequence.

2 ___ 5 ____ 3 

2 5
2 3

2 3 leads to better opportunity to find bigger LIS!


Questions:
1. strictly increasing
2. duplicates
3. [int32] -> length of the subsequence (int)

*/

class Solution{
    private int lowerBound(List<Integer> arr, int lo, int hi, int target){
        while(lo<hi){
            int mid = lo + (hi-lo)/2;

            if(arr.get(mid) >= target)  hi = mid;
            else  lo = mid+1;
        }

        return lo;
    }

    // 10,9,2,5,3,7,101,18
    // 2 3 7 18

    public int lengthOfLIS(int[] arr) {
        List<Integer> lis = new ArrayList<>();
        List<Integer> lis_idx = new ArrayList<>();
        
        int[] par = new int[arr.length];
        Arrays.fill(par, -1);

        for(int i=0;i<arr.length;i++){
            int num = arr[i];

            int pos = lowerBound(lis, 0, lis.size(), num);
            if(pos == lis.size()){ // can have 1 more element to the lis
                lis.add(num);

                if(pos > 0) par[i] = lis_idx.get(pos-1); 
                lis_idx.add(i);
                
            }
            else{ //if we replace lis[pos] with num, LIS still remains same size but has better probability of exapnding (num  <=  lis[pos])
                lis.set(pos, num);

                if(pos > 0) par[i] = lis_idx.get(pos-1);
                lis_idx.set(pos, i);
            }
        }

        // lis rebuilding
        int idx = lis_idx.get(lis_idx.size()-1);
        Deque<Integer> st = new ArrayDeque<>();
        while(idx != -1){
            st.push(arr[idx]);
            idx = par[idx]; 
        }

        while(!st.isEmpty()){
            System.out.println(st.pop());
        }

        return lis.size();
    }
}
