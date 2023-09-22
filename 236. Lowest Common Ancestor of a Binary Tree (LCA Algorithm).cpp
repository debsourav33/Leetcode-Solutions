/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define null nullptr

class Solution {
public:
    const int N = 1e5+5;
    const int logN = 18;

    map<int,int> mother, level;
    map<int,vector<int>> parent;
    vector<int> nodes;

    void bfs(TreeNode* node, int p){
      if(node==nullptr) return;

      int val = node->val;
      nodes.push_back(val);
      
      mother[val] = p;
      parent[val].push_back(p);
      level[val] = p == -1 ? 0 : level[p] + 1;
      
      bfs(node->left, val);
      bfs(node->right, val);
    }

    void buildSparseTree(){
      for(int j=1;j<=logN;j++)
        for(auto u: nodes){
          int parent_one_step_up = parent[u][j-1];
          if(parent_one_step_up==-1)
            parent[u][j] = -1;  
          else
            parent[u][j] = parent[parent_one_step_up][j-1];
        }
    }

    int get_lca(int n1, int n2){
      if(level[n1]<level[n2])  swap(n1,n2);

      for(int j=logN;j>=0;j--){
        int p = parent[n1][j];
        if(p==-1)  continue;

        if(level[p]>=level[n2])  n1 = p;
      }

      if(n1==n2)  return n1;

      for(int j=logN;j>=0;j--){
        int p = parent[n1][j];
        int q = parent[n2][j];

        if(p!=q && p!=-1){
          n1 = p,
          n2 = q;
        }
      }

      return mother[n1];
    }

    TreeNode* lowestCommonAncesto(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)  return nullptr;
        if(root->val==p->val || root->val==q->val)  return root;

        TreeNode* leftFind = lowestCommonAncesto(root->left,p,q);
        TreeNode* rightFind = lowestCommonAncesto(root->right,p,q);

        if(leftFind!=nullptr && rightFind!=nullptr)  return root;
        return leftFind != nullptr ? leftFind : rightFind;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        nodes.clear();
        TreeNode* ret = lowestCommonAncesto(root,p,q);
        bfs(root,-1);

        for(auto u: nodes){          
          for(int j=0;j<=logN;j++)
            parent[u].push_back(-1);
        }

        buildSparseTree();

        int new_res = get_lca(p->val,q->val);
        cout<<new_res<<endl;

        if(new_res != ret->val)  return null;
        return ret;

    }
};
