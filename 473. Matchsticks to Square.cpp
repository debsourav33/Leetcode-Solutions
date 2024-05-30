/*
Time: O(n*2^n)
Space: O(n*2^n)

Bitmask DP (States: 1. how many sides are done, 2. which matchsticks have been used):
Always form a side first before going for other sides and keep track of which matchsticks have been used so far
When do we know a side is formed? If the remaining sum of matchsticks are divisible by a side's length
*/

class Solution {
public:
    bool res = false;
    long long n, target;

    int sum = 0;
    vector<int> m;
    vector<vector<int>> dp;

    int call(int done, int mask){
        //remaining match sticks' lengths' sum
        int rem_sum = 0;
        for(int i=0;i<n;i++){
            if((mask & (1<<i)) == 0)  rem_sum += m[i];  
        }
        
        //to prevent thinking a side done when no match stick is taken, check if rem_sum <= sum
        if(rem_sum < sum && rem_sum % target == 0){  //When do we know a side is formed? If the remaining sum of matchsticks are divisible by a side's length
            done++;
        }

        if(done == 4)  return 1; //4 sides done
        //if(rem_sum == 0)  return 0; //we can't take any more matchsticks

        int &mem = dp[done][mask];
        if(mem != -1)  return mem;
        
        //pick any one possible matchstick for current side and make recursive call
        int ans = 0;
        for(int i=0;i<n;i++){
            if((mask & (1<<i)) == 0)  ans = ans || call(done, mask | (1<<i)); 
            if(ans)  return mem = 1;
        }

        return mem = 0;
    }
    

    bool makesquare(vector<int>& m) {
        this->m = m;
        n = m.size();
        dp = vector(4, vector<int>((1<<n)+1,-1));

        //sort(m.begin(), m.end(), greater<int>());
        
        for(auto& u: m){
            sum += u;
        }

        if(sum%4)  return false;
        target = sum/4;

        for(auto& u: m){
            if(u > target)  return false;
        }

        return call(0, 0);      
    }
};
