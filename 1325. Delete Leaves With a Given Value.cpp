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

/*
Time: O(n)
Space: O(h) (Stack space)

Post Order Traversal:
Recursively reach the leaf nodes first and update the left and right children (they may have changed to nullptr (if they became leaf and has values = target)
Then check if the new node is/has become leaf and has target value, in which case the node is removed and returned as nullptr
*/

class Solution {
public:
    TreeNode* call(TreeNode* node, int &target){
        if(node==nullptr)  return node;

        auto left = call(node->left, target);
        auto right = call(node->right, target);

        //the left and right child may have changed to nullptr (if they became leaf and has values = target)
        //so update the new left and right children
        node->left = left;
        node->right = right;

        //if leaf and has target value, then this done is done for
        //nice hack for leaf check: node->left == node->right evaluates to node->left == nullptr && node->right == nullptr 
        if(node->val == target && node->left == node->right)  return nullptr;
        return node;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return call(root, target);
    }
};
