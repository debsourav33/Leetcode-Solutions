class Solution {

    String format(StringBuilder sb){
      //remove all X
      StringBuilder ret = new StringBuilder();
      for(int i=0;i<sb.length();i++){
        if(sb.charAt(i)!='X')  ret.append(sb.charAt(i));
      }

      return ret.toString();
    }

    public String removeDuplicates(String s, int k) {
      StringBuilder sb = new StringBuilder(s);
      int n = s.length();

      int[] prev = new int[n];
      int[] cnt = new int[n];
      int last = 0;

      cnt[0] = 1;
      for(int i=1;i<n;i++){ 
        prev[i] = last;

        if(s.charAt(i)==s.charAt(last))
          cnt[i] = cnt[last] + 1;
        else
          cnt[i] = 1;

        if(cnt[i]==k){  //k same chars found, replace all of them with X and update prev
          int update_idx = i;

          for(int j=0; j<k; j++){
            sb.setCharAt(update_idx,'X');
            update_idx = prev[update_idx]; //follow the chain to traverse back to the previous occurance of same character
          }

          last = update_idx;  // now last points to the previous index of the deleted substring
        }
        else{
          last = i;  //otherwise last points to this index
        }

      }

      System.out.println(sb);
      return format(sb);
      }
}
