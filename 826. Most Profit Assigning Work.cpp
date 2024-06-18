/*
TC: O(nlogn)
Space: O(n)
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& profit, vector<int>& w) {
        //pair difficulty and profit together
        vector<vector<int>> v;
        for(int i=0; i<dif.size();i++){
            v.push_back({dif[i],profit[i]});
        }

        //sort by profit
        sort(v.begin(), v.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[1] > v2[1]; 
        });

        //sort workers array
        sort(w.begin(),w.end());
        int last = w.size();
        int ans = 0;
        
        //starting from the highest profitabble task
        //binary search to find how many (not occupied) workers can be assigned to this task (comparing with difficulty)
        for(auto& u: v){
            int l = lower_bound(w.begin(), w.end(), u[0]) - w.begin();
            if(l < last){
                ans += u[1] * (last-l);
                last = l; //last denotes from which position, remaining workers are occupied
            }
        }

        return ans;
    }
};
