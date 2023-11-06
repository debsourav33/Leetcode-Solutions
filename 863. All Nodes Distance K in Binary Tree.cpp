/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    #define null nullptr
    vector<TreeNode*> par;
    int k;

    //if we set_up parents, we can run bfs/dfs from target node (to left, right and parent)
    void set_parents(TreeNode* node, TreeNode* p){
      if(node==null)  return;

      par[node->val] = p;

      set_parents(node->left,node);
      set_parents(node->right,node);
    }

    vector<int> ans;

    void dfs(TreeNode* node, int distance, int last){
      if(node==null)  return;
      if(distance==k)  ans.push_back(node->val);

      TreeNode* parent = par[node->val];

      TreeNode* adj[] = {node->left, node->right, parent};

      for(TreeNode* nd: adj){
        if(nd!=null && nd->val != last)  get_k_nodes(nd,distance+1,node->val);
      } 
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      this->k = k;
      par = vector<TreeNode*>(501,null);
      set_parents(root,null);


      ans.clear();
      dfs(target,0,-1);
      return ans;
    }
};
