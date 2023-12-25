class Solution {
public:
    vector<int> par;

    int find(char c){
      int pos = c-'a';
      if(par[pos]==pos)  return pos;

      return par[pos] = find(par[pos] + 'a');
    }

    void unions(char c1, char c2){
      int p1 = find(c1);
      int p2 = find(c2);

      //try to have the parent that is lexicographically smallest
      if(p1<p2)  par[p2] = p1;
      else par[p1] = p2;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++)  par.push_back(i);

        for(int i=0;i<s1.length();i++)  unions(s1[i],s2[i]);

        string ans = "";

        for(char c: baseStr)  ans += ('a'+find(c));

        return ans;
    }
};
