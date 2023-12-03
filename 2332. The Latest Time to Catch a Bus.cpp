class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& pass, int capacity) {
        sort(buses.begin(),buses.end());
        sort(pass.begin(),pass.end());

        vector<int> in;
        vector<int> cnt(buses.size(), 0);
        int b = 0, p =0, taken = 0;
        while(b<buses.size() && p<pass.size()){
          int taken = 0;
          while(taken < capacity){
            if(p==pass.size() || pass[p]>buses[b])  break;

            in.push_back(pass[p]);
            taken++;
            p++;
            cnt[b]++;
          }
          b++;
        }

        // case 1 - last bus is not full
        if(cnt[buses.size()-1] < capacity){
          int b =buses[buses.size()-1], j = in.size()-1;

          while(j>=0 && b == in[j] ){
            b--;
            j--;
          }

          return b;

        }

        //case 2 - last bus is full
        for(int i=in.size()-1;i>=1;i--){
          if(in[i-1] != in[i] - 1)  return in[i] - 1;
        } 

        return in[0]-1;

    }
};
