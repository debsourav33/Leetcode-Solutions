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

    int call(TreeNode* node, int k){
      if(node==nullptr)  return 0;

      int left_size = call(node->left, k);
      if(left_size == k-1)  ans = node->val;  //means the left_child is the (k-1)th smallest, so this node is the kth smallest
      int right_size= call(node->right, k-left_size-1);  //we found left_size + 1 (for this node) nodes to have smaller value then the right child, so subtract (left_size+1) from k

      return left_size+right_size+1;
    }

    int kthSmallest(TreeNode* root, int k) {
        call(root,k);
        return ans;
    }
};
