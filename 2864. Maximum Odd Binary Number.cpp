class Solution {
public:
    //inplace and one pass
    string maximumOddBinaryNumber(string s) {
        int last = 0;
        for(int i=0;i<s.length();i++){
            auto tmp = s[i];
            s[i] = '0';

            if(tmp=='1')  s[last++] = '1';
        }

        s[last-1] = '0';
        s[s.length()-1] = '1';

        return s;
    }
};
