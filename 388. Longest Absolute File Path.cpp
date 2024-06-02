/*
Time: O(n)
Space: O(1)

Recursively call for the next line
States: current position in input, nesting level, current offset (curr directory name length)
Return: the end position of current nested block
*/

class Solution {
public:
    string s;
    int maxi = 0;
    int call(int pos, int nest, int offset){
        if(pos==s.length())  return pos;

        //cout<<pos<< " "<<nest<<" "<<offset<<endl;
        

        int p = pos;
        bool file = false;
        //traverse until the end of line
        while(p<s.length() && s[p]!='\n'){
            if(s[p] == '.')  file = true; //its a file iff a '.' is in the path
            p++;
        }

        int curr_offset = offset + (p-pos);
        if(file){ //if file, we update maxi variable
            maxi = max(maxi, curr_offset);
        }

        // recursively call for the all the nested blocks under this directory
        while(p<s.length() && s[p] == '\n'){
            int nxt = p+1;
            int tabs = 0;

            //try to find tabs 1 more time than current nested level
            while(nxt < s.length() && s[nxt] == '\t'){
                tabs++;
                nxt++;

                if(tabs == nest+1)  break;
            }

            if(tabs == nest+1){ //if nest+1 tabs found
                p = call(nxt, nest+1, curr_offset+1); //call for the nested block
                //cout<<p<<endl;
            }
            else{ //otherwise, no more nested block
                break;
            }
        }

        return p;
    }

    int lengthLongestPath(string input) {
        s = input;
        int p = 0;

        while(p<s.length()){
            p = call(p,0,0);
            if(s[p] == '\n')  
                p++;
        }

        return maxi;
    }
};
