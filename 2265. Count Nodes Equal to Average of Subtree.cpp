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
    int ans = 0;
    pair<int,int> call(TreeNode* node){
      if(node==nullptr)  return make_pair(0,0);

      auto left = call(node->left);
      auto right = call(node->right);

      int count = left.first + right.first + 1; //1 for this node
      int sum = left.second + right.second + node->val;

      int avg = sum/count;
      if(avg == node->val)  ans++;

      return make_pair(count,sum);
      
    }

    int averageOfSubtree(TreeNode* root) {
      ans = 0;
      call(root);
      return ans;
    }
};
