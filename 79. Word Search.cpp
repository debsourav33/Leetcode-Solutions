/*
Time: 4^(m*n) (branching factor = 4 for every cell)
Space: m*n (for visited array)

Recursively visit neighboring cells as long as the next character of board matches the next unmatched character in word
and maintain visited array.. when a cell's neighbor has been explored, backtrack and make the cell unvisited
*/
class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;

    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    bool is_valid(int r, int c){
        return r>=0 && r<m && c>=0 && c<n && !vis[r][c];
    }

    bool call(int p, int r, int c, vector<vector<char>>& board, string& word){
        if(board[r][c] != word[p])  return false;
        if(p==word.length()-1)  return true;

        vis[r][c] = true;
        
        for(auto &d: dir){
            int nxt_r = r+d[0], nxt_c = c+d[1];

            if(is_valid(nxt_r, nxt_c)){
                bool res = call(p+1, nxt_r, nxt_c, board, word);
                if(res)  return true; //if exist, return immidiately
            }
        }

        vis[r][c] = false; //backtrack

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        vis = vector(m, vector(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool res = call(0, i, j, board, word);
                if(res)  return true;
            }
        }

        return false;
    }
};
