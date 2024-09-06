/*
Time: O(n * max_roll * dice_sides)
Space: O(n * max_roll * dice_sides)

DP State: current pos, last dice, streak of the last dice
*/
const int mod = 1e9+7;
const int dice_sides = 6;

class Solution {
public:
    int n;
    vector<int> rollMax;
    vector<vector<vector<int>>> dp;

    int call(int p, int last, int streak){
        if(p == n)  return 1;

        int &mem = dp[p][last][streak];
        if(mem != -1)  return mem;

        int sum = 0;
        for(int i=1;i<=dice_sides;i++){
            if(i != last){
                sum += call(p+1, i, 1); //new streak begins!
                sum %= mod;
            }
            if(i == last && streak < rollMax[last-1]) { //dice is mapped to dice-1 in rollMax
                sum += call(p+1, last, streak+1); //streak continues (only if it doesn't exist rollMax[last])
                sum %= mod;
            }
        }

        return mem = sum;

    }
    int dieSimulator(int n, vector<int>& rollMax) {
        this->n = n;
        this->rollMax = rollMax;

        int max_roll = 0;
        for(auto u: rollMax)  max_roll = max(max_roll, u);

        dp = vector(n, vector(dice_sides+1, vector(max_roll+1, -1)));

        int ret = 0;
        for(int i=1;i<=dice_sides;i++){ //try placing all possible side at the first place
            ret += call(1, i, 1);
            ret %= mod;
        }

        return ret;
    }
};
