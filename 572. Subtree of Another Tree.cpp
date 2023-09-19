/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  void prefix_func(string p, int pre[]){
    int now = -1;

    pre[0] = -1;

    //start from 1 becase we need proper prefix
    //if we taken prefix from 0, now and pre[now] would have been the same resulting in infinite loop
    for(int i=1;i<p.length();i++){
        while(now!=-1 && p[i]!=p[now+1]){
            now = pre[now];
        }
        
        if(p[i] == p[now+1])  pre[i] = ++now;
        else pre[i] = -1;
    }
  }

  bool kmp(string text, string p){
      int n = p.length();
      int pre[n];
      
      prefix_func(p,pre);

      int now = -1;

      for(int i=0;i<text.length();i++){
          while(now!=-1 && text[i]!=p[now+1]){
              now = pre[now];
          }
          
          if(text[i] == p[now+1])  ++now;
          else now = -1;

          if(now==p.length()-1)  return true;
      }

      return false;
  }

  string serialize(TreeNode* root){
    if(root==nullptr)  return "N";

    //to prevent suffix matching (like 12N <-> 2N), concat root->val twice
    return to_string(root->val) + to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
  }


  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      string text = serialize(root);
      string pat = serialize(subRoot);

      cout<<text<<endl;
      cout<<pat<<endl;
      return kmp(text,pat);
      return false;
  }
};
