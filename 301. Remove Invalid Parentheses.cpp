/*
Time: O(2^n) (worst case = all left paranthese '((((((' )
Space: O(N) (not considering return array)

Use backtracking, at every position, we can take the parantheses or skip it
pruning:
    1. if at any stage, taken right count > left count, prune
    2. calculate the minimum cuts needed first, then for every valid string generated, only take those with that no. of removals
*/

class Solution {
public:
    unordered_set<string> ans;
    int left1 = 0, left2 = 0, balance = 0, cuts = 0;

    string s;
    string res = "";

    int cut = 0;

    void call(int pos){
        if(pos - res.size() > cut)  return;

        //if an alphanumeric character encountered, we have to take it - no alternative
        if(pos < s.length() && s[pos] != '(' && s[pos] != ')'){
            res += s[pos];
            call(pos+1);
            res.pop_back();
            return;
        }

        for(int i=pos;i<s.length();i++){
            if(s[i] == '(' )  balance++;
            else if(s[i] == ')' )  balance--;
            
            res += s[i];
            
            if(balance >= 0)  call(i+1); //don't call for negative balance ( more ')' )

            //backtrack
            if(s[i] == '(' )  balance--;
            else if(s[i] == ')' )  balance++;            
            res.pop_back();
        }

        if(balance == 0){
            int cuts = s.length() - res.length(); //no. of removals for current string
            if(cuts == cut){
                ans.insert(res);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        this->s = s;

        //find minimum cuts required for valid string
        int balance = 0;
        for(auto &c: s){
            if(c=='(')  balance++;
            else if(c == ')'){
                if(balance == 0)  cut++;
                else  balance--;
            }
        }
        cut += balance;


        call(0);

        return vector<string>(ans.begin(), ans.end());
    }
};
