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
    Space: O(h)

    Traverse while maintaining levels and determine levels for x and y nodes.
    For any node, if the children have values x and y, we know they are siblings, not cousins.
    So, we can make their levels unequal and return.

    After the function returns, simply check if the levels are equal or not.
    */

    void call(TreeNode* r, int l, int x, int y, int &levelX, int &levelY){
      if(r==nullptr)  return;

      //if x and y are children of current node, they are siblings, not cousins
      if(r->right != nullptr && r->left!=nullptr){
        if((r->right->val == x && r->left->val == y) ||
          (r->right->val == y && r->left->val == x)){
            //fill levels with garbage unequal values
            levelX = -1;
            levelY = -2;

            return;
          }
      }

      if(r->val == x)  levelX = l;
      if(r->val == y)  levelY = l;

      call(r->left, l+1, x, y, levelX, levelY);
      call(r->right, l+1, x, y, levelX, levelY);
    }

    bool isCousins(TreeNode* root, int x, int y) {
      int lx, ly;
      call(root, 0, x, y, lx, ly);

      //if parents are same, lx = -1 and ly = -2, so this condition will fail
      return lx == ly;
    }
};
