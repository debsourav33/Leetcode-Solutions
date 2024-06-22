/*
Time: O(n)
Space: O(1)

Squeeze Window
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        int l = 0, r = 0, l_cnt = 0, r_cnt = 0;
        int ans = 0;

        for(int i=0;i<v.size();i++){
            if(v[i] % 2 == 1)  l_cnt++, r_cnt++;

            //Squeeze from the left to find a window with k odds

            //sqeeze left border until the window [l ... i] has k odds in it
            //O(1) amortized - runs a cumulative of N time
            while(l_cnt > k && l<r){
                if(v[l] % 2 == 1)  l_cnt--;
                l++;
            }

            //sqeeze right border until the window [r ... i] has k-1 odds in it
            //O(1) amortized - runs a cumulative of N time
            while(r_cnt > k-1 && r<=i){
                if(v[r] % 2 == 1)  r_cnt--;
                r++;
            }

            //the window starting from [l...r] and ending in [i] has k odds in it 
            if(l_cnt == k){
                ans += r-l;
                //cout<<i<<" "<<l<<" "<<r<<endl;
            }
        }

        return ans;
    }
};
