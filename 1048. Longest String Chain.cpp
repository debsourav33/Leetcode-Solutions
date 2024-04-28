/*
Time: O(n * w^2)
Space: O(n * w)

DP
 First, sort the array so that shorter words come first
 Then, for each word, get all possible parents (by removing one character at a time)
 And consult the DP table to get the longest path formed until that parent
 take the longest path maxi out of all parents
 and make the dp[curr_word] = 1 + maxi (1 for the current word)
*/
class Solution {
public:

    //removes a char at a given position and returns the resultant string
    string cut(string& w, int pos){
        string ret = "";
        for(int i=0;i<w.length();i++){
            if(i==pos)  continue;
            ret += w[i];
        }

        return ret;
    }

    int longestStrChain(vector<string>& words) {
        //sort by the order of word length
        auto cmp = [](string& w1, string& w2){
            return w1.length() < w2.length(); //smaller word first
        };
        sort(words.begin(), words.end(), cmp);

        unordered_map<string, int> dp; //dp["xyz"] -> 0

        //track the maximum length found so far
        int ans = 0;

        for(auto &w: words){
            int n = w.length();

            //generate all the possible parents
            int maxi = 1;
            for(int i=0;i<n;i++){
                string parent = cut(w, i);
                
                int par_length;
                //if(dp.count(parent) == 0)  par_length = 0;
                par_length = dp[parent];

                int curr = 1 + par_length;
                maxi = max(curr, maxi);      
            }

            dp[w] = maxi; //longest path for this word = 1 + longest path among all parents
            ans = max(ans, dp[w]);           
        }

        return ans;
    }
};
