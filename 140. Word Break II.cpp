/*
Time: O(2^n * n) (worst case - each character can be word, so the second recursive call is made)
Space: O(n) + O(dict)

0-1 backtracking (choose/don't choose)
*/

class Solution {
public:
    string s;
    unordered_set<string> has;

    vector<string> res;
    vector<string> v;

    string word = "";

    //get words joined together comma separated as a sentence
    string getSentence(vector<string>& v){
        string ret = v[0];
        for(int i=1;i<v.size();i++){
            ret += ' ';
            ret += v[i];
        }

        return ret;
    }

    void call(int p){
        //base case - if we ran out of traversing s
        if(p == s.length()){
            //word == "" means all letters of s are consumed, so we get a valid sentence
            if(word == "")  res.push_back(getSentence(v));
            return;
        }

        //don't take the word
        word += s[p];
        call(p+1);
        word.pop_back(); //backtrack

        //try taking the word if it is in the dict
        word += s[p];
        string original = word; //store original

        if(has.find(word) != has.end()){ //if word is in set
            v.push_back(word);
            word = ""; //new word begins

            call(p+1);

            v.pop_back(); //backtrack
            word = original; //restored to original
        }

        word.pop_back(); //backtrack
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;

        //push all words into the set for faster lookup
        for(auto &w: wordDict){
            has.insert(w);
        }

        call(0);

        return res;
    }
};
