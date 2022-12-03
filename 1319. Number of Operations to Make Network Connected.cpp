class Solution {
public:
    static const int maxn= 1e5+5;

    vector<int> v[maxn];
    int vis[maxn], parent[maxn], redundant;


    void dfs(int u){
        vis[u]= 1;
        
        for(int i=0;i<v[u].size();i++){
            int nd= v[u][i];
            if(nd==parent[u]) continue;

            if(!vis[nd]){
                parent[nd]= u;
                dfs(nd);
            }
            else{
                redundant++;
                //cout<<u<<" - "<<v[u][i]<<endl;
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i=0;i<maxn;i++)  v[i].clear();
        redundant = 0;
        
        memset(vis, 0, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        
        for(auto con: connections){
            v[con[0]].push_back(con[1]);
            v[con[1]].push_back(con[0]);
        } 
        
        int components = 0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                components++;
                dfs(i);
            }
        }
        
        redundant /= 2; //bidirectional edges are constructed twice!
        
        //cout<<redundant<<" "<<components<<endl;
        
        if(redundant<components-1)  //we don't have enough redundant cables
            return -1;
        return components-1;  //to connected all disjoint components
        
        
    }
};