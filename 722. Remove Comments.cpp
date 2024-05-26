/*
Time: O(n)
Space: O(n)

Recursively call for the next line
(States: p = current src line number, curr = current comment-removed src line number, open = if inside block comment)
If block comment encountered in middle of the line or line comment encountered at start of the line, 
then don't increment curr (add next code characters to same line)
*/

class Solution {
public:
    vector<string> src;
    
    vector<string> ret;
    
    void cln(int p, int curr, bool open){
        if(p==src.size())  return;

        if(ret.size() == curr)  ret.push_back("");

        string& s = src[p];

        for(int i=0;i<s.length();i++){
            if(s[i]=='/' && i+1<s.length()){
                 if(!open && s[i+1] == '*'){ //start marker of block comment (if its not already inside block comment)
                    open = true;
                    i++;
                    continue;
                 }
                 if(!open && s[i+1] == '/'){ //start marker of line comment (if its not already inside block comment)
                    break; //line comment means wer are done processing with this line
                 }
            }

            if(s[i]=='*' && i+1<s.length()){ //end marker of block comment
                if(open && s[i+1] == '/'){ //if its inside a blockcomment!
                    open = false;
                    i++;
                    continue;
                }
            }


            if(!open){
                ret[curr] += s[i];
            }
        }

        if(ret[curr].length() > 0 && !open)  cln(p+1,curr+1,open); //if current line has no characters, then dont increment curr
        else  cln(p+1,curr,open);
    }

    vector<string> removeComments(vector<string>& source) {
        src = source;

        cln(0,0,false);
        return ret;
    }
};
