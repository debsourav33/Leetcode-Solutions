class Solution {
public:
    const int INF = 1e9+9; // this constant is not used in the code
    int dp[502][502], n1, n2; // dp array to store intermediate results, and variables to store the lengths of the input strings
    string s, t; // variables to store the input strings

    int call(int p1, int p2){ // function to calculate and return the Levenshtein distance
        if(p1==n1 && p2==n2)  return 0; // if both indices point to the end of the strings, the distance is 0
        if(p1==n1 || p2==n2)  return (n1-p1+n2-p2);
        /* if one of the indices point to the end of the string,
        the distance is the remaining length of the other string */
        if(dp[p1][p2]!=-1)  return dp[p1][p2]; // check if the distance has already been calculated
        if(s[p1]==t[p2])  return dp[p1][p2] = call(p1+1,p2+1);
        /* if the characters at the current indices are equal,
        the distance remains the same and we move to the next characters */
        else return dp[p1][p2] = 1 + min(call(p1+1,p2), call(p1,p2+1));
        /* if the characters are not equal, we increment the distance
        and take the minimum of either deleting a character from s or inserting a character into s */
    }

    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp)); // initializing dp array with -1
        s = word1; n1 = s.length(); // storing the input strings and their lengths
        t = word2; n2 = t.length();
        return call(0,0); // calling the function to calculate and return the Levenshtein distance
    }
};
