class Solution {
public:
    
    vector<vector<int>> mat;
    int rows, cols;

    vector<int> traverse(int r, int c){
      vector<int> ret;
      int turn = (r+c)%2;

      while(r>=0 && c<cols){
        ret.push_back(mat[r][c]);
        --r;
        ++c;
      }

      if(turn)  reverse(ret.begin(),ret.end());      
      
      return ret;
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ret; 
        this->mat = mat;
        rows = mat.size();
        cols = mat[0].size();

        //starting - all rows first column
        for(int i=0;i<rows;i++){
          auto trav = traverse(i,0);
          ret.insert(ret.end(),trav.begin(),trav.end());
        }


        //starting - last row all columns
        for(int i=1;i<cols;i++){
          auto trav = traverse(rows-1,i);
          ret.insert(ret.end(),trav.begin(),trav.end());
        }

        return ret;
    }
};
