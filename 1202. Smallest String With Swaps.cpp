/*
The similarity is transitive

So, group the similar indices into components
- Traverse the indices of s and find the component of that index
- Get the minimum element from that component and place it in that index and remove it from the component (so that it's not used twice)
*/

class Solution {
public:
    int n;
    vector<int>  par;
    vector<multiset<int>> component;

    int find(int r){
      if(par[r]==r)  return r;

      return par[r] = find(par[r]);
    }

    void unions(int x, int y){
      int p1 = find(x);
      int p2 = find(y);

      if(p1==p2)  return;

      if(component[p1].size() < component[p2].size())  swap(p1,p2);

      par[p2] = p1;
      for(auto u: component[p2]) component[p1].insert(u); 
    }



    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      n = s.length();
      for(int i=0;i<n;i++){
        par.push_back(i);
        
        multiset<int> st;
        st.insert(s[i]);
        component.push_back(st);
      }

      for(auto v: pairs){
        unions(v[0],v[1]);
      }

      for(int i=0;i<n;i++){
        int parent = find(i);
        multiset<int> &comp = component[parent];

        char replacement = *comp.begin();
        comp.erase(comp.begin());

        s[i] = replacement;
      }

      return s;
    }
};
