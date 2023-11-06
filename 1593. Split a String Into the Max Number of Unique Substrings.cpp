class Solution {
public:
    int n;
    string s;
    int ans = 0;
    unordered_map<string,int> m;
    int cnt = 0;

    //backtracking solution
    //using unordered_map to check if any substring occurs twice
    void call(int pos){
      if(pos==n){
        ans = max(ans,cnt);
        return;
      }

      string str = "";
      for(int i=pos;i<n;i++){
        str = str + s[i];
        
        if(m.count(str)==0) m[str] = 0;
        m[str]++;
        cnt++;  //one more substring taken

        if(m[str] == 1){  //if this substring only occured once, proceed with recursive call
          call(i+1);
        }

        cnt--; //that substring is eliminated
        m[str]--;
      }
    }

    int maxUniqueSplit(string s) {
      this->s = s;
      n = s.length();

      call(0);
      return ans;
    }
};
