class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, streak = 0;
        int last[127];

        for(int i=0;i<127;i++)  last[i] = -1;

        for(int i=0;i<s.length();i++){
            int pos = s[i];

            streak = min(streak + 1, i - last[pos]);
            ans = max(ans, streak);

            last[pos] = i;
        }

        return ans;
    }
};