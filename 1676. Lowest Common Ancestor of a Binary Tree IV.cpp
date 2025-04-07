/**
 Time: O(N)   N = nodes in the tree
 Space: O(h+k)  k = nodes.size()

 For every node, find
 left = the no. of nodes found in the left subtree 
 right = the no. of nodes found in the right subtree
 mid = if the current node is one of the node in the nodes set

 the first (deepest) node having left + right + mid = n will be the LCA

 */
class Solution {
public:
    int n;
    TreeNode* ans = nullptr;
    unordered_set<int> s;

    int call(TreeNode* root){
        if(!root)  return 0;

        int left = call(root->left);
        int right = call(root->right);
        int mid = (s.find(root->val) != s.end());

        if(left + right + mid == n){
            if(!ans)  ans = root;
        }

        return left+right+mid;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        n = nodes.size();
        for(auto u: nodes)  s.insert(u->val);

        call(root);
        return ans;
    }
};
