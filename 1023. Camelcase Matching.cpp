/*
Time: O(n)
Space: O(1)

Try to match all uppercase letters of S with that of P (lowercase letters dont matter)
If there's any extra ones, we know we cant form S from P
*/
class Solution {
public:
    bool can(string& s, string &p){
        int i=0, j=0;
        while(i<s.length() && j<p.length()){
            if(s[i] == p[j]){ //both upper letters and match
                i++;
                j++;
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){ //smaller letters can be inserted into pattern so they are all valid
                i++;
            }
            else{ //s[i] is a uppercase letter that doesn't match p, so we cant form s from p
                return false;
            }
        }

        //check for any remaining uppercase letters in s
        while(i<s.length()){
            if(s[i] >= 'a' && s[i] <= 'z'){
                i++;
            }
            else{ //s[i] is a uppercase letter that doesn't match p[i]
                return false;
            }
        }

        //all characters in pattern must be consumed
        return j == p.length();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(int i=0;i<queries.size();i++)  ans.push_back(can(queries[i], pattern));
        return ans;
    }
};