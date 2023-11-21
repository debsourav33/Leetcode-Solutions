class Solution {
public:
    long long countBadPairs(vector<int>& v) {
        long n = v.size();
        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
          v[i] = v[i] - i;
          m[v[i]]++;
        }

        // bad pairs = total pairs - good pairs
        long ans = (n * (n-1))/2;

        for (auto& pair : m) {
          long same_cnt = pair.second;
          ans -= (same_cnt * (same_cnt-1))/2;
        }

        return ans;

    }
};
