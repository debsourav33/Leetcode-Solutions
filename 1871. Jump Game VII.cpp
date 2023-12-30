/*

Cell no #k is reachable if and only if,
any cell between (k-maxJump, k-minJump) is reachable
-> we just need to check if the range sum of (k-maxJump, k-minJump) is greater than 0 (sum = no. of cells reachable in this range)
*/

class Solution {
public:
    int n;
    vector<int> pref;

    int range_sum(int from, int to){
      if(to<0 || from>=n)  return 0;
      from = max(0,from);
      to = min(n-1,to);

      int st = from > 0 ? pref[from-1] : 0;
      int endi = pref[to];

      return endi-st;
    }

    bool canReach(string s, int mini, int maxi) {
      n = s.length();
      pref = vector(n,0);
      
      pref[0] = 1;

      for(int i=1;i<n;i++){
        pref[i] = pref[i-1];
        
        if(s[i]!='0')  continue;

        int reachable = (range_sum(i-maxi, i-mini) >= 1);
        //cout<<i<<" "<<reachable<<endl;
        pref[i] += reachable;
      }   


      return range_sum(n-1,n-1);


    }


};
