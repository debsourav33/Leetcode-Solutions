/*
The meetings are instaneous, so the relations are transitive
i.e. meetings between (1,2) and (2,3) are equivalent to meeting between (1,2,3)
So we can use Union-Find
But, we have to do it for the set of meetings that take place in the same time (can't use transitivity with previous meetings). 
*/

class Solution {
public:
    vector<int> par;
    unordered_set<int> s;

    int find(int a){
        if(par[a]==a)  return a;
        return par[a] = find(par[a]);
    }

    void unions(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b)  return;

        if(s.find(a)!=s.end())  par[b] = a;
        else  par[a] = b;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int f) {
        s.clear();

        par.clear();
        for(int i=0;i<n;i++)  par.push_back(i);

        s.insert(0);
        s.insert(f);

        map<int,vector<vector<int>>> m;
        for(auto &v: meetings){
            int t = v[2];
            if(m.count(t)==0)  m[t] = {};
            m[t].push_back({v[0],v[1]});
        }

        //ordered map (with key = time) will make sure meetings appear in sorted order of time
        for(auto &pair: m){
            auto vec = pair.second;

            for(auto &v: vec){
                unions(v[0],v[1]);
            }

            for(auto &v: vec){
                int a = find(v[0]);

                if(s.find(a) != s.end()){
                    s.insert(v[0]);
                    s.insert(v[1]);
                }
            }

            //backtrack dsu so that this timestamp's meetings don't effect future ones (but, the hashset of secret knowers is not backtracked)
            for(auto &v: vec){
                par[v[0]] = v[0];
                par[v[1]] = v[1];
            }
        }

        vector<int> ret;
        for(auto &element: s){
            ret.push_back(element);
        }

        return ret;
    }
};
