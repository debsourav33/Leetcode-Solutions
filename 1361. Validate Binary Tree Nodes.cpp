class Solution {
public:
    

  bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
      vector<int> vis(n,0);
      vector<int> par(n,-1);
      queue<int> q;
      
      for(int i=0;i<n;i++){
        int left = l[i];
        int right = r[i];
        if(left!=-1)  par[left] = i;
        if(right!=-1)  par[right] = i;
      }

      int root = -1;
      for(int i=0;i<n;i++){
        if(par[i]==-1){
          if(root!=-1)  return false; //two components
          root = i;
        } 
      }

      cout<<root<<endl;
      if(root==-1)  return false;

      q.push(root);
      vis[root] = 1;
      
      while(!q.empty()){
        int node = q.front();
        q.pop();
        
        int left = l[node];
        int right = r[node];

        if(left!=-1){
          if(vis[left])  return false;
          vis[left] = 1;
          q.push(left);
        }
        if(right!=-1){
          if(vis[right])  return false;
          vis[right] = 1;
          q.push(right);
        }
      }
        
      for(int i=0;i<n;i++){
        if(!vis[i])  return false;  //2 components
      }


      return true;
    }
};
