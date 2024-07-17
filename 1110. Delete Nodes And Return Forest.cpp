/*
Time: O(n)
Space: O(h) + O(dels)

Recursively traverse and break links with the parent if the node is to be deleted
If a node's parent is deleted and the node itself is not deleted, it becomes a root of the new tree in the forest

*/

class Solution {
public:
    unordered_set<int> del;
    vector<TreeNode*> roots;

    TreeNode* call(TreeNode* node, bool parent_deleted){
        if(node == nullptr)  return nullptr;

        bool node_deleted = false;
        if(del.find(node->val) != del.end())  node_deleted = true;

        //If a node's parent is deleted and the node itself is not deleted, it becomes a root of the new tree in the forest
        if(parent_deleted && !node_deleted)  roots.push_back(node);
        
        //if the left node is to be deleted, it will return null and so the link to the left subtree will be deleted (same for right)
        node->left = call(node->left, node_deleted);
        node->right = call(node->right, node_deleted);

        return node_deleted ? nullptr : node; //return null if it's to be deleted
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto u: to_delete)  del.insert(u);
        call(root, true);
        return roots;
    }
};
