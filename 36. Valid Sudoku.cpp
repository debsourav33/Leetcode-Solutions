/*
Time: O(rows*cols)
Space: O(rows*cols)

For every row, column and block, maintain a separate hashset
And for every element traversed, find its row, column and block and check if the corresponding hashset contains the value already
If yes, return false
If the whole traversal is done and breach is not found, return true
*/

class Solution {
public:
    //hepler functiont to get block no. given row and column
    int get_block(int r, int c){
        return r/3 * 3 + c/3;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows_set[9], cols_set[9], blocks_set[9];

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.')  continue;
                int value = board[i][j];

                int row = i, col = j, block = get_block(i,j);           

                if(rows_set[row].find(value) != rows_set[row].end()
                || cols_set[col].find(value) != cols_set[col].end()
                || blocks_set[block].find(value) != blocks_set[block].end()){
                    //cout<<i<<" "<<j<<endl;
                    return false;
                }

                rows_set[row].insert(value);
                cols_set[col].insert(value);
                blocks_set[block].insert(value);

            }
        }

        return true;
    }
};
