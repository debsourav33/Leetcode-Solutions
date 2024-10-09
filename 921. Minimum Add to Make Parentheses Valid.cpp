/*
Time: O(n)
Space: O(1)

Keep count of unmatched opening parantheses
When a closing parantheses encountered
    - if open_count > 0, there's an matching opening parantheses, decrement open_count by one
    - if open_count == 0, there's no matching opening parantheses, add one to the answer (we need to insert one opening parantheses)

At the end, if there are remaining unmatched open parantheses, add the count to the answer (since, we need to insert as many closing parantheses)
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int moves = 0;
        int opens = 0;

        for(auto c: s){
            if(c=='(')  opens++;
            else{ //closing par
                if(opens)  opens--; //matching opening par found for this closing par
                else  moves++; //no matching opening par found, insert an opening one
            }  
        }

        moves += opens; //insert as many closing parantheses as there are opening ones remaining
        opens = 0; //no more open parantheses remaining

        return moves;
    }
};
