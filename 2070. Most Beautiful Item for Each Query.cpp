//runtime o(n^2)

class Solution {
public:
    int isPali[1005][1005];
    string s;

    //this has a state of i*j, so takes o(n^2) to populate isPali[][] table and once populated it will return in constant time
    bool isPalindrome(int i, int j){
      if(i>=j)  return true;
      if(isPali[i][j]!=-1)  return isPali[i][j];
      
      return isPali[i][j] = s[i]==s[j] && isPalindrome(i+1,j-1);
    }
    
    string longestPalindrome(string str) {
       memset(isPali,-1,sizeof(isPali));  

       s = str;      
       int n = s.length();

       
       int st=0, endi=0;
       int sz=1;

       //iterate from the biggest size and return when palindrome is found
       
       for(int sz=n;sz>=1;sz--){
         for(int i=0;i<=n-sz;i++){
           if(isPalindrome(i,i+sz-1)){ //this has independent total runtime of o(n^2)
             st = i, endi = i+sz-1;
             
             int pal_len = endi-st+1;
             return s.substr(st,pal_len);
           }
         }
       } 

       //cout<<st<<" "<<endi<<endl;

       int pal_len = endi-st+1;
       return s.substr(st,pal_len);
       


    }
};/*
Time: O(nlogn)
Space: O(n)

1. sort in asc order of price, for same price have the highest beauty first
2. find max beauty till each price
3. binary search for each query to find highest possible beauty
*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();

        //sort in asc order of price, for same price have the highest beauty first
        auto cmp = [](vector<int> &a, vector<int> &b){
            if(a[0] != b[0])  return a[0] < b[0];
            return a[1] > b[1];
        };

        sort(items.begin(), items.end(), cmp);

        //find max_till each price idx 
        vector<int> max_till(n, -1);
        max_till[0] = items[0][1];
        for(int i=1;i<n;i++){
            if(items[i][1] > max_till[i-1]){
                max_till[i] = items[i][1]; 
            }
            else{
                max_till[i] = max_till[i-1];
            }
        }

        //binary search for each query to find highest possible beauty
        vector<int> ans;
        for(auto q: queries){
            int lo = 0, hi = n-1;

            while(lo<hi){
                int mid = (lo+hi+1)/2;

                if(items[mid][0] <= q)  lo = mid;
                else  hi = mid-1;
            }

            if(items[lo][0] > q )  ans.push_back(0);
            else  ans.push_back(max_till[lo]);
        }

        return ans;
    }
};
