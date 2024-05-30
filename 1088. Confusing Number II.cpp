/*
Time: O(5^9) (branching factor: 5, max_depth: 9)
Space: O(1)

Use backtracking.. At every position we can insert only magic characters
Check to see if the number generated is confusing-number 
*/

class Solution {
public:
    int n;
    vector<int> digits;
    vector<int> ops = {0, 1, 6, 8, 9};
    unordered_map<int,int> m;
    
    Solution(){
        m[1] = 1;
        m[6] = 9;
        m[9] = 6;
        m[8] = 8;
        m[0] = 0;
    }
    
    //checks if num is confusing
    //that is the mapped characters in reverse must not be same as the original
    int check(int num){
        int tmp = num;
        int rev = 0;
        while(num){
            int d = num%10;
            rev = rev * 10 + m[d];
            num /= 10;
        }

        //cout<<tmp<<" "<<rev<<endl;
        return rev != tmp;
    }
    
    int num;
    int ans = 0;
    
    void call(int p, int n){
        if(num > n)  return;
        if(p == 10){
            //cout<<ans<<endl;
            ans += check(num);
            return;
        }
        
        //have to choose one digit (among 1,6,8,9,0) for every position
        int orig = num;
        for(auto o: ops){
            if(p == 0 && o>1)  break;
            
            num = num * 10 + o;
            call(p+1, n);
            num = orig; //backtrack
        }
    }
    
    int confusingNumberII(int n){
        call(0,n);
        return ans;
    }
};  
    

int main() {
    Solution sol;
    int n = 999999999;
    
    
    //sol.check(16);
    //sol.check(806);
    cout<<sol.confusingNumberII(n)<<endl;
}
