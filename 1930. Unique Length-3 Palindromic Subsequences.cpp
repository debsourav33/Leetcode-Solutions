class Solution {
public:
    int countPalindromicSubsequence(string s) {
      int n = s.length();
      int ans = 0;
      vector<int> occur[26];

      for(int i=0;i<n;i++){
        int idx = s[i] - 'a';
        occur[idx].push_back(i);
      }

      //for each character, try to place it on 1st and 3rd position, and find how many unique characters we can place in 2nd position so that we can have a unique palindrome
      //First find the first and last occurence of the character
      //Then binary search to find the occurence of each character that falls in this range
      for(int i=0;i<26;i++){
        int sz = occur[i].size();
        if(sz==0)  continue;

        int first = occur[i][0];
        int last = occur[i][sz-1];

        //how many unique chars are there between first and last occurence of character 'a'+i?
        for(int j=0;j<26;j++){
          //binary search to get the minimum position ( > first) of this character 'a'+j
          int sz2 = occur[j].size();
          int pos = upper_bound(occur[j].begin(),occur[j].end(),first) - occur[j].begin();
          if(pos==sz2)  continue;

          int oc = occur[j][pos];
          if(first<oc && oc<last)  ans++;
        }        
      }

      return ans;
    }
};
