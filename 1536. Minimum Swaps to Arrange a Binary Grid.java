class Solution {
    public int minSwaps(int[][] grid) {
        int ans = 0;
        int n = grid.length;

        int[] trailingZeroes = new int[n];

        //compute trailing zeroes for all rows
        for(int i=0;i<n;i++){
          trailingZeroes[i] = 0;
          for(int j=n-1;j>=0;j--){
            if(grid[i][j]!=0)  break;
            trailingZeroes[i] ++;
          }
        }

        for(int i=0;i<n;i++){
          System.out.println(trailingZeroes[i]);
        }

        for(int i=0;i<n;i++){
          int zeroNeeded = n-i-1; //zeroes needed in first row is n-1, second n-2 and so on
          int swap = 0;
          boolean found = false;

          for(int j=0;j<n;j++){
            if(trailingZeroes[j] == -1 )  continue; //already swapped
            if(trailingZeroes[j] >= zeroNeeded){
              trailingZeroes[j] = -1; //swap this row to top (1 row once) and mark it swapped
              found = true; //found a row that has enough zeroes
              break;
            }
            else swap++; //we need one swap of rows
          }

          if(!found)  return -1;  //not possible to make valid gried
          ans += swap;
        }

        return ans;
    }
}
