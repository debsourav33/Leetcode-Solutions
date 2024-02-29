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
    vector<int> vals;
    bool call(TreeNode* node, int level){
        if(node == nullptr)  return true;

        //for even level, val should be odd, and vice versa
        //so level and val should not have same even check
        if(level%2 == node->val%2)  return false;

        //first value found for this level
        if(vals.size()==level)  vals.push_back(node->val);
        else{ //not the first, so compare with the previous 
            int last = vals[level];
            int curr = node->val;
            if(level%2==0 && curr <= last)  return false;
            if(level%2==1 && curr >= last)  return false;

            //current value becomes the latest one found for this level
            vals[level] = curr;
        }

        return call(node->left, level+1) &&  call(node->right, level+1); 
    }

    bool isEvenOddTree(TreeNode* root) {
        return call(root, 0);
    }
};
