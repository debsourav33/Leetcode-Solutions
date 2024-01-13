class Solution {
public:
    vector<int> v;
    int maxi, n;

    //convert a string to bitmask (one set bit for each character in string)
    int get_mask(string &s){
      int mask = 0;

      for(char c: s){
        int pos = c - 'a';

        //check if duplicate characters present
        if(mask & (1<<pos))  return -1;

        mask |= (1<<pos);
      }

      return mask;
    }

    int get1count(int mask){
      int cnt = 0;
        //find no. of 1 bits (= no. of unique characters)
        for(int i=0;i<26;i++){
          if(mask & (1<<i))  cnt++;
        }
      return cnt;
    }

    //why add res parameter?
    //to make it a tail-call recursion!
    void call(int pos, int mask, int res){
      maxi = max(res, maxi);
      
      for(int i=pos;i<n;i++){
        //mask & v[i] > 0 means atleast 1 same character foind in v[i]
        if(mask & v[i])  continue;

        call(i+1, mask | v[i], get1count(mask | v[i])); //if not, take all the characters of v[i], set bit for them and proceed
      }
    }

    
    int maxLength(vector<string>& arr) {
        maxi = 0;
        v.clear();
        
        for(string &s: arr){
          int mask = get_mask(s);
          if(mask!=-1)  v.push_back(mask);  //mask = -1 means duplicate characters in same string
        }

        n = v.size();

        call(0,0,0);

        return maxi;
    }
};
