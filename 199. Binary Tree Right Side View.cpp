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
    /*
    Time: O(n)
    Space: O(h) (h = height of the tree)

    Traverse in preorder/inorder/post order (in all, right node comes after left)
    Maintain levels as you make recursive call
    Then add the node value in the level-th index
    Sinc, for a level, the right most node will come after all the left nodes,
    right most node's value will override any other in the level-th index
    */
    void preorder(TreeNode* node, int level, vector<int> &v){
      if(node==nullptr)  return;
      if(v.size()==level)  v.push_back(node->val);

      v[level] = node->val; //this will override any left nodes values in v[level]
      preorder(node->left, level+1, v);
      preorder(node->right, level+1, v);
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        preorder(root,0,v);
        return v;
    }
};
