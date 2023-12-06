class Solution {
public:
    //sum for all elements between a and b
    int getSum(int a, int b){
      if(a>b)  return 0;
      
      int n  = (b-a+1);
      return ((a+b)*n)/2;
    }

    int totalMoney(int n) {
      int ans = 0;
      int div = n/7;

      //add for k days (k<=n, k is divisble by 7)
      ans += 7 * getSum(4,4+div-1);

      //add for remaining (n-k) days
      int remaining = n%7;
      ans += getSum(div+1, div+remaining);
      

      return ans;
    }
};
