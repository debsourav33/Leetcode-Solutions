/*
Time: O(NlogN)
Space: O(N)


Classic sticks-and-stones

**|****|**

Recursion nCk
DP n^n^k


Algo:
Consider every idx as splitting point. Then values to be added sums are idx (previous group's end border) and idx+1 (next group's start border) (adjacent pair)

min --> 

1. adjacent pair sums --> (n-1) sums
2. sort them
3. pick the first k-2 (+ 0th + (n-1)th )

max --> 

1. adjacent pair sums --> (n-1) sums
2. sort them
3. pick the last k-2 (+ 0th + (n-1)th )


Input: weights = [1,3,5,1], k = 2
Output: 4

ps = [4 6 8]
i = 2

mini = 1 + 1 + 4
maxi = 1 + 1 + 8
 */

class Solution {
    public long putMarbles(int[] arr, int k){
        int n = arr.length;
        if(n == 1)  return 0;

        int groups = n-1;
        int[] pairSums = new int[groups];
        
        for(int i=0;i<n-1;i++){
            pairSums[i] = arr[i] + arr[i+1];
        }

        Arrays.sort(pairSums);

        // we need k-1 splitting points
        long mini = arr[0]+arr[n-1]; //first and last is compulsory
        for(int i=0;i<k-1;i++){ //smallest k-1 splitPoints
            mini += pairSums[i];
        }

        long maxi = arr[0]+arr[n-1];
        for(int i=0;i<k-1;i++){
            maxi += pairSums[groups-1-i]; //largest k-1 splitPoints
        }

        return maxi - mini;
    }
}
