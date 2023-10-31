class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        //lets say we are at position i and we have pref[i]
        //find x such that pref[i] ^ x = pref[i+1]
        //                => pref[i] ^ pref[i+1] = x
        
        vector<int> ret;
        ret.push_back(pref[0]);

        for(int i=1;i<pref.size();i++)
          ret.push_back(pref[i-1]^pref[i]);   

        return ret;
    }
};
