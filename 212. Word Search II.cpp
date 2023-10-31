class Solution {
public:
    struct Trie{
      struct node{
        int leaf;
        int count;

        node* child[26];

        node(){
          leaf = 0;
          count = 0;
          for(int i=0;i<26;i++){
            child[i] = nullptr;
          }
        }
      };

      node* root = new node();

      void insert(node* nd, string &word, int pos){
        if(pos==word.length()){
          nd->leaf = 1;
          return;
        }

        int idx = word[pos] - 'a';
        if(nd->child[idx]==nullptr)  nd->child[idx] = new node();
        

        nd->child[idx]->count++;
        cout<<word[pos] << " "<<nd->child[idx]->count<<endl;
        insert(nd->child[idx], word, pos+1);
      }

      void remove(node* nd, string &word, int pos){
        if(pos==word.length()){
          nd->leaf = 0;
          return;
        }

        int idx = word[pos] - 'a';
        if(nd->child[idx]==nullptr)  nd->child[idx] = new node();

        nd->child[idx]->count--;
        cout<<word[pos] << " "<<nd->child[idx]->count<<endl;
        insert(nd->child[idx], word, pos+1);
      }

      node* query(node* nd, char c){
        int idx = c - 'a';
        return nd->child[idx];
      }
    }t;

    vector<vector<char>> grid;
    int visited[13][13];
    int lop[4] = {0,0,1,-1};
    int rop[4] = {1,-1,0,0};
    vector<string> ans;
    map<string,bool> taken;
    string word;
    int m,n;

    //use backtracking to generate all possible words starting from cell (i,j) and going only to adjacent cells as long as we keep getting match in the trie
    void call(int i, int j, Trie::node* nd){
      //cout<<word<<endl;
      if(nd==nullptr || nd->count==0){
        return;
      }
      if(nd->leaf){
        if(taken.count(word)==0){ //avoid duplicates
          t.remove(t.root,word,0);  //no need same word twice
          ans.push_back(word);
          taken[word] = true;
        }
      }

      for(int k=0;k<4;k++){
        i += lop[k];
        j += rop[k];

        if(i<0 || i>m-1 || j<0 || j>n-1 || visited[i][j]){
          //cout<<i<<" "<<j<<endl;
          i -= lop[k];
          j -= rop[k];
          continue;
        }

        
        word += grid[i][j];
        visited[i][j] = 1;

        int idx = grid[i][j] - 'a';
        //printf("For %d-%d\n",i,j);
        call(i,j, nd->child[idx]);

        visited[i][j] = 0;
        word.pop_back();
        i -= lop[k];
        j -= rop[k];
      }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        grid = board;
        m = board.size();
        n = board[0].size();
        

        t.root = new Trie::node();

        for(auto word: words){
          t.insert(t.root, word, 0);
        }

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            visited[i][j] = 1;
            word += grid[i][j];

            //printf("Calling for %d-%d\n",i,j);
            int idx = grid[i][j] - 'a';
            call(i,j,t.root->child[idx]);
            
            word.pop_back();
            visited[i][j] = 0;
          }
        }
        // //remove duplicates
        // vector<string> ret;
        // sort(ans.begin(),ans.end());
        // ret.push_back(ans[0]);
        // for(int i=1;i<ans.size();i++)
        //   if(ans[i]!=ans[i-1])  ret.push_back(ans[i]);  
        
        return ans;
    }
};
