/*
TC: O(N)
SC: O(N)

Find latest '0', find the previous '5'/'0', remove all chracters between and after them
Find latest '5', find the previous '7'/'2', remove all chracters between and after them

Return minimum removals of these 2 approaches
*/

class Solution {
public:
    int latest(string &s, int c, int from){
        for(int i=from; i>=0; i--)  if(s[i]==c)  return i;
        return -1;
    }

    int find(char c, char l1, char l2, string &s){
        int n = s.length();
        int ans = n;

        int last = latest(s, c, n-1);
        if(last != -1){
            int prev_l1 = latest(s, l1, last-1);
            int prev_l2 = latest(s, l2, last-1);

            int best = max(prev_l1, prev_l2);
            if(best!=-1){
                ans = (n-1-last) + (last-1-best);
            }
        }

        return ans;
    }

    int minimumOperations(string& s) {
        int n = s.length();
        int op1 = find('0','0','5',s);
        int op2 = find('5','2','7',s);

        if(min(op1,op2) < n)  return min(op1,op2);
        else{
            int non_zero = 0;
            for(auto c: s)  if(c != '0')  non_zero++;
            return non_zero;
        }
    }
};
