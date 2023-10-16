class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> v = vector(r+1, 1);

        //base case
        v[0] = 1;
        
        for(int i=1;i<=r;i++){
          //1 in two boundaries
          v[0] = 1;
          v[i] = 1;

          int last = v[0];
          for(int j=1;j<i;j++){
            int tmp = v[j];
            v[j] = v[j] + last; //current index val is = (val in same index + val in prev index) in previous iteration . val in prev index in previous iteration will be lost so preserve it in temporary variable
            last = tmp;
          }

        }

        return v;
    }
};
