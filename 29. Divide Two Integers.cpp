class Solution {
public:
    
    using ll = long long;
    vector<ll> cnt;
    vector<ll> total;

    //generate d multiplied by 2's multiplicants 
    //d*1, d*2, d*4 ...
    //this is because 
    // 1. we don't need multiplication do achieve that, just adding twice means doubling
    // 2. we can reach any value (quotient) using 2's multiplicants
    void gen_counts(ll num, ll d){
      cnt = {1};        
      total = {d};

      for(int i=1; ;i++){
        int new_cnt = cnt[i-1] + cnt[i-1];
        ll new_total = (ll) total[i-1] + (ll) total[i-1];

        if(new_total > num)  break;

        cnt.push_back(new_cnt);
        total.push_back(new_total);
      }

      //for(int i=0;i<cnt.size();i++)  cout<<cnt[i]<<" "<<total[i]<<endl;
      
    }

    ll get_quotient(ll num){
      ll ans = 0;
      ll sum = 0;

      for(int i=total.size()-1;i>=0;i--){
        if(sum > num - total[i])  continue;

        sum += total[i];
        ans += cnt[i];
      }

      return ans;
    }

    int divide(int num, int d) {
      bool neg = false;
      
      //edge cases
      if(num==0)  return 0;
      if(d== -1 && num == -INT_MAX-1)  return INT_MAX;
      
      if((num<0 && d >0) || (num>0 && d<0))  neg = true;

      ll number = num;
      ll div = d;

      //take absolute values
      number = number > 0 ? number : -number;
      div = div > 0 ? div : -div;

      gen_counts(number,div);
      ll ans = get_quotient(number);

      //append - if num and d have opposite signs
      if(neg)  return -ans;
      return ans;
    }
};
