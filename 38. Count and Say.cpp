class Solution {
public:
    string countAndSay(int n) {
        if(n==1)  return "1";

        string say = countAndSay(n-1);
        string this_say = "";

        int streak = 1;
        for(int i=1;i<say.length();i++){
          if(say[i]==say[i-1])  streak++;
          else{
            this_say += to_string(streak) + say[i-1];
            streak = 1;
          }
        }

        this_say += to_string(streak) + say[say.length()-1];
        return this_say;
    }
};
