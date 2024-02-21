class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        
        // 10101010
        // 10110011
        //    -
        // The first position where they differ, all later positions will hold 0 in the result
        // why?
        // lets say from position i we have left = 0----, right bit = 1----
        // that means we must have encountered 10000 between them, bitwise and between left and 10000 = all 0s
        for(int i=30;i>=0;i--){

          bool bitL = left & (1<<i);
          bool bitR = right & (1<<i);
          
          if(bitL==bitR){
              res |= (bitL<<i);
          }
          else  break;
        }

        return res;
        
    }
};
