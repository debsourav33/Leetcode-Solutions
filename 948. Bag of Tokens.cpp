class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        //edge case
        if(n==0)  return 0;

        vector<int> pre(n,0);
        
        sort(tokens.begin(),tokens.end());
        pre[0] = tokens[0];

        for(int i=1;i<n;i++)  pre[i] = pre[i-1] + tokens[i];

        int ans = upper_bound(pre.begin(), pre.end(), power) - pre.begin();
        cout<<ans<<endl;
        if(ans==0)  return ans; //we need atleast one score to do face-down operation

        int loss = 0;

        //from the end of the tokens (bigger elements first), pick one by one, do face-down,
        //add to power and check how many faceups possible from start of the tokens (smaller first)

        for(int i=n-1;i>=1;i--){
            power += tokens[i];
            loss++; //for every facedown, we lose one point

            int res = upper_bound(pre.begin(), pre.begin()+i, power) - pre.begin();
            ans = max(ans, res - loss);
        }

        return ans;
    }
};
