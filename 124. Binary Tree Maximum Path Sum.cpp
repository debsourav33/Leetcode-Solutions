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
    int ans, max_node;


    int call(TreeNode* root){
      if(root==nullptr)  return 0;

      max_node = max(max_node, root->val);

      int left = call(root->left);  //0 or greater
      int right = call(root->right); //0 or greater
      //printf("For %d, left = %d, right = %d\n",root->val,left,right);

      int longest_down_route = max(left,right);
      longest_down_route = max(longest_down_route + root->val, 0);


      //if we connect left and route down route, the middleman (root->val) must be counted
      //so longest path is either left route or right route or both combined with middleman root
      int longest_path = max(root->val + left + right, max(left, right));
      ans = max(ans, longest_path);

      return longest_down_route; //0 or greater
    }

    int maxPathSum(TreeNode* root) {
        ans = max_node = -1005;

        call(root);

        //if no positive node exists
        if(max_node < 0)  return max_node;
        
        return ans;
    }
};
