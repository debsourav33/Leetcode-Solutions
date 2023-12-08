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
    //hashmap : key - string representation of subtree, value : vector of roots of such subtrees
    unordered_map<string, vector<TreeNode*>> m;

    string traverse(TreeNode* root){
      if(root==nullptr)  return "";

      //represent the subtree in a string
      string subtree = to_string(root->val) + '(' +  traverse(root->left) + ')' + '(' +  traverse(root->right) + ')';

      if(m.count(subtree)==0)  m[subtree] = {};
      m[subtree].push_back(root);  //keep in hash table

      return subtree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;

        m.clear();
        traverse(root);

        for(auto cup: m){
          auto vec = cup.second;

          //vec.size() >= 2 means more than 1 root has same subtree representation
          if(vec.size() >=2)  ans.push_back(vec[0]);
        }

        return ans;
    }
};
