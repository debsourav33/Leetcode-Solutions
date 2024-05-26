/*
Time: O(n)
Space: O(1)

Determine left and right boundary such that if the elements in this boundary is sorted, the entire array is sorted
-> Left boundary is the leftmost index l such that v[l] < v[k], for some k > l (i.e., there is a bigger element than v[l] on its right)
-> Right boundary is the rightmost index r such that v[r] < v[k], for some k > l (i.e., there is a smaller element than v[r] on its left)

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int n = v.size();

        int left = 1e9, right = -1e9;

        //Left boundary is the leftmost index l such that v[l] < v[k], for some k > l (i.e., there is a bigger element than v[l] on its right)
        int mini = v[n-1];
        for(int i=n-2;i>=0;i--){
            if(v[i] > mini )    left = i;

            mini = min(mini, v[i]);
        }

        //Right boundary is the rightmost index r such that v[r] < v[k], for some k > l (i.e., there is a smaller element than v[r] on its left)
        int maxi = v[0];
        for(int i=1;i<n;i++){
            if(v[i] < maxi)  right = i;

            maxi = max(maxi, v[i]);
        }
        

        if(left == 1e9)  return 0; //whole array is sorted, no op!
        return right-left+1;

    }
};
