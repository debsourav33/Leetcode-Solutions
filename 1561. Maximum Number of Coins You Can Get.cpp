class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());

        int ans = 0;
        int collected = 0;

        //leave first quarter (n/3) for Bob 
        //for the last 2 quarters, start from the last (largest pile):
        //allocate it to Alice, you take the pile before it (immediate smaller)
        //repeat until you reach Bob's quarter
        for(int i=n-2;i>=n/3;i-=2)  ans += piles[i];

        return ans;
    }
};
