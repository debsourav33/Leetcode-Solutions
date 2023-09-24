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
    stack<int> st[20];

    void dfs(TreeNode* node, int level = 0, int flip = false){
      if(node==nullptr)  return;

      int u = node->val;

      if(level%2==1){  //odd level check
        if(!flip)
          st[level].push(u);
        else{
          int flipped_val = st[level].top();
          node->val = flipped_val;
          //cout<<u<<" becomes "<<node->val<<endl;

          st[level].pop();
        }
      }
      
      dfs(node->left, level+1, flip);
      dfs(node->right, level+1, flip);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root);
        dfs(root,0,true); //can't skip any default argument!

        return root;
    }
};
