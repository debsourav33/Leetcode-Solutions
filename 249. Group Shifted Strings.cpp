/*
Time: O(l*n)  where l is the average length of the strings
Space: O(l*n)
*/

class Solution {
public:
    //hash function that calculates the hash by computing the difference between every pair of adjacent characters
    // all one length strings belong to same group and they will have hash = ""
    string get_hash(string s){
        string hash = "";

        for(int i=1;i<s.length();i++){
            char c = 'a' + (s[i]-s[i-1]+26)%26; //mod for cyclic property
            hash += c; 
        }

        return hash;
    }

    vector<vector<string>> groupStrings(vector<string> v){
        int n = v.size();
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ret;

        for(int i=0;i<n;i++){
            string s = v[i];
            
            // group similar words under same key
            m[get_hash(s)].push_back(s); 
        }

        for(pair<string,vector<string>> p: m)  ret.push_back(p.second);

        return ret;
    }
};
