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
Space: O(log(n)) (Height Balanced)

Recursively build branches with mid element as the root, left to mid-1 as the left branch and mid+1 to right as the right branch
*/

class Solution {
public:
    typedef TreeNode node;
    vector<int> v;

    node* call(int l, int r){
        if(l>r)  return nullptr;

        int mid = (l+r)/2;

        //to keep height balanced, put mid element as root and the 2 equal halves on left and right
        node* root = new node(v[mid]);
        
        root->left = call(l, mid-1);
        root->right = call(mid+1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        v = nums;
        return call(0, v.size()-1);
    }
};
