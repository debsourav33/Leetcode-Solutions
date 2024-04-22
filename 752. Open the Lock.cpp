/*
Time: 10^w (here w = wheels count (4) and 10 = max value a wheel can get)
Space: 10^w (to store all possible distinct states)

Run BFS
From every state, we can go to another state by
    - picking one of the 4 wheels, and incrementing/decrementing its value by 1
    - if that state is deadend, we discard it, otherwise we push it to the queue
*/

class Solution {
public:
    unordered_map<string,int> level;
    unordered_set<string> deads;

    void bfs(string source, string target){
        //edge case
        if(deads.find(source) != deads.end())  return;
        
        queue<string> q;
        q.push(source);
        level[source] = 0;        

        while(!q.empty()){
            string s = q.front();
            q.pop();

            if(target == s)  return;

            for(int i=0;i<4;i++){
                int digit = s[i] - '0';

                //increment 1
                string copy = s;
                int new_digit = (digit + 1)%10;
                copy[i] = new_digit + '0';

                //if not deadend, and not yet visited
                if(deads.find(copy) == deads.end() &&
                   (level.count(copy) == 0 /*|| level[copy] > level[s] + 1*/))
                   {
                        level[copy] = level[s] + 1;
                        q.push(copy);

                        //cout<<s<<" "<<copy<<" "<<level[copy]<<" "<<endl;
                   }

                //decrement 1
                copy = s;
                new_digit = (digit - 1 + 10)%10;
                copy[i] = new_digit + '0';

                //if not deadend, and not yet visited
                if(deads.find(copy) == deads.end() &&
                   (level.count(copy) == 0 /*|| level[copy] > level[s] + 1*/))
                   {
                        level[copy] = level[s] + 1;
                        q.push(copy);

                        //cout<<s<<" "<<copy<<" "<<level[copy]<<" "<<endl;
                   }
            }
        }
    }

    int openLock(vector<string>& deadends, string target) {
        for(auto s: deadends){
            deads.insert(s);
        }

        bfs("0000",target);

        if(level.count(target)==0)  return -1; //couldn't reach
        return level[target];
    }
};
