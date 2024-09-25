/*
w = words length in average
Time: O(n*w)
Space: O(n*w)


Use prefix trie
*/

class Solution {
public:
    struct Trie{
        struct node{
            int val = 0;
            node* children[26] = {};
        };

        node* root;

        Trie(){
            root = new node;
        }

        //for each prefix, we increment the value of the node by 1
        void insert(node* nd, string &w, int p){
            if(p == w.length())  return;

            int idx = w[p] - 'a';
            auto child = nd->children[idx];

            if(child == nullptr)  child = nd->children[idx] = new node();
            child->val += 1; //increment the value of the node by 1

            insert(child, w, p+1);
        }

        //for each prefix, we keep adding the value of the corresponding node
        int query(node* nd, string &w, int p){
            if(p == w.length())  return 0;

            int idx = w[p] - 'a';
            auto child = nd->children[idx];

            return child->val + query(child, w, p+1); //keep adding the value of the corresponding node
        }
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ret(n, 0);

        Trie t;

        for(auto &w: words){
            t.insert(t.root,w,0);
        }

        for(int i=0;i<n;i++){
            auto &w = words[i];
            ret[i] = t.query(t.root,w,0);
        }

        return ret;
    }
};
