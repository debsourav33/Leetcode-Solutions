class Solution {
public:
    int characterReplacement(string s, int k) {
        //deque to store indices of the chars other than our desired char K
        deque<int> dq; 
        int ans = 0;


        for(int j=0;j<26;j++){
          char c = char('A'+j);
          
          dq.clear();
          for(int i=0;i<k+1;i++)  dq.push_back(-1);

          for(int i=0;i<s.length();i++){
            if(s[i]!=c){
              dq.pop_front(); 

              //edge case (k=0, no replacement possible)
              if(k==0){
                dq.push_back(i); 
                continue;
              }
            }

            //dq.front() points to the lowest index from which there's atmost k other characters
            int front = dq.front();
            int streak = i-front;
            ans = max(ans, streak);

            if(s[i]!=c){
              dq.push_back(i); 
            }
          }
        }

        return ans;
    }
};
