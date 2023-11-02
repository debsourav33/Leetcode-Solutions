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
    int n;
    vector<TreeNode*> nodes;

    //collect all the nodes in a vector
    void traverse(TreeNode* root){
      if(root==nullptr)  return;
      nodes.push_back(root);

      traverse(root->left);
      traverse(root->right);
    }

    vector<vector<int>> dp;

    //dp with memoization
    int call(TreeNode* root, int last){
      if(root==nullptr)  return 0;
      int &mem = dp[root->val][last];
      if(mem!=-1)  return mem;
      

      return (last==0) ? mem = 1 + call(root->left, 1-last) : mem = 1 + call(root->right, 1-last); 
    }


    int longestZigZag(TreeNode* root) {
        traverse(root);
        n = nodes.size();

        for(int i=0;i<n;i++)  nodes[i]->val = i;  //assign unique values for memoization

        dp = vector(n+1,vector(2,-1));

        int ans = 0;

        for(TreeNode* node: nodes){
          ans = max(ans, call(node,0));
          ans = max(ans, call(node,1));
        }

        return ans-1; //the starting node doesn't count
    }
};
