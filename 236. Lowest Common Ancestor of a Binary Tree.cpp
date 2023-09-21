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
    const int N = 1e5+5;
    const int logN = 18;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)  return nullptr;
        if(root->val==p->val || root->val==q->val)  return root;

        TreeNode* leftFind = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightFind = lowestCommonAncestor(root->right,p,q);

        if(leftFind!=nullptr && rightFind!=nullptr)  return root;
        return leftFind != nullptr ? leftFind : rightFind;
    }
};
