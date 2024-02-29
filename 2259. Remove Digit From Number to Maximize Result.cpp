/*
If there's only one digit, you have to remove it
If there's more, select the first one that is smaller than the following digit (if there's no such occurance, pick the last one)
(because whenever you are removing a digit which has a smaller digit following, this will be the minimum number from that position)
*/

class Solution {
public:
    string removeDigit(string num, char digit) {
        string ret = "";
        int cnt = 0, cut = 0, n = num.length();

        for(auto c: num)  cnt += (c==digit);

        for(int i=0;i<n;i++){
            auto c = num[i];
            if(c==digit){
                if(cnt==1 || i == n-1 || num[i+1] > c){
                    cut = i;
                    break;
                }
                cnt--;
            }
        }

        for(int i=0;i<n;i++){
            if(i!=cut)  ret += num[i];
        }

        return ret;
    }
};
