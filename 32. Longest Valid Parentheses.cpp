class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.length();
        stack<int> st;
        vector<int> score_at(n,0);

        for(int i=0;i<n;i++){
          if(s[i]=='('){
            score_at[i] = 0;
            st.push(i);
          }
          else if(st.empty()){  // ')' found but no matchig '('
            score_at[i] = 0;
          }
          else{ // ')' found with matching '('
            int match = st.top();
            st.pop();

            int prev = max(match-1,0);

            //score is 2 (for this pair '(' and ')' ) + score of the last idx + matches until (= score of) the previous idx of the matching '(' 
            score_at[i] = 2 + score_at[i-1] + score_at[prev];
            ans = max(ans, score_at[i]);
          }
        }

        return ans;
    }
};
