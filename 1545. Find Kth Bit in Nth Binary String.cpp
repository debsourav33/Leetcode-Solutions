/*
Time: O(n)
Space: O(1)


Find the pattern : 
.... mid ....k..  the k bit is gained by reversing the bit at position mid - (mid-k)
Follow this pattern until you hit a 2's power (that bit must be the divider 1, or the 1st bit which is 0)
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if(k == 1)  return '0';

        vector<int> pows = {1};

        for(int i=1;i<=n+1;i++) pows.push_back(pows[pows.size()-1] * 2 );
        
        int cnt = 0;
        
        while(1){
            int p = lower_bound(pows.begin(), pows.end(), k) - pows.begin();
            if(pows[p] == k)  break;
            
            cnt++;
            p--;
            k = pows[p] - (k-pows[p]); 
        }

        //edge case: fist bit is 0
        if(k == 1)  return cnt%2 == 0 ? '0' : '1';
        //other cases: 2's power hit, determine how many times we have flipped the 1 bit after hitting that 2's power
        return cnt%2 == 0 ? '1' : '0';

    }
};
