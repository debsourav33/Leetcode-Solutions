class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int> ret;
        multiset<int,greater<int>> s;

        for(int i=0;i<k;i++)  s.insert(v[i]);

        ret.push_back(*s.begin());  //element for first window

        for(int i=k;i<v.size();i++){
          s.erase(s.find(v[i-k])); //remove the slided out element
          s.insert(v[i]); //insert the slided in element
          
          int maxi = *s.begin();
          ret.push_back(maxi);
        }

        return ret;
    }
};
