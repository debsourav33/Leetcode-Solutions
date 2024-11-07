/*
Time: O(n)
Space: O(1)

For each bit position, find out how many numbers have 1 bit in that position.
Then, find the position having the highest count.
That count is the answer (because all the numbers that have 1 bit for that partcular position can be taken to make the largest combo)
*/

class Solution {
public:
    int largestCombination(vector<int>& a) {
        int ans = 0;
        unordered_map<int,int> m;

        //For each bit position, find out how many numbers have 1 bit in that position.
        for(auto u: a){
            for(int i=0;i<31;i++){
                if(u & (1<<i))  m[i]++;

                //find the position having the highest count.
                ans = max(ans, m[i]); 
            }
        }

        return ans; // that highest count is the answer (because all the numbers that have 1 bit for that partcular position can be taken to make the largest combo)
    }
};



