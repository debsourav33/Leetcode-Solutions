/*
Time: O(n)
Space: O(h)

Use 2 DFS
1. For the first time, find the sum of values of all the levels of the binary tree.
2. For the second time, update the value of the node with the sum of the values of the current level - current and sibling node’s values. (Hint: Every node can have maximum 2 children -> every node can have maximum one sibling)
*/
class Solution {
public:

    int lvl_sum[100000];

     //For the first dfs, find the sum of values of all the levels of the binary tree.
    void dfs(TreeNode* node, int lvl){
        if(node == nullptr)  return;

        //if(lvl_sum.size() == lvl)  lvl_sum.push_back(0);

        lvl_sum[lvl] += node->val;
        
        dfs(node->left, lvl+1);
        dfs(node->right, lvl+1);
    }

    //For the second time, update the value of the node with the sum of the values of the current level - current and sibling node’s values. (Hint: Every node can have maximum 2 children -> every node can have maximum one sibling)
    void dfs2(TreeNode* curr, int sibling_sum, int lvl){
        if(!curr)  return;

        int sum = lvl_sum[lvl];
        
        sum -= curr->val;
        sum -= sibling_sum;

        int left_sum = curr->left ? curr->left->val : 0;
        int right_sum = curr->right ? curr->right->val : 0;

        curr->val = sum;

        dfs2(curr->left, right_sum, lvl+1);
        dfs2(curr->right, left_sum, lvl+1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root,0);      
        dfs2(root,0,0);    

        return root;
    }
};
