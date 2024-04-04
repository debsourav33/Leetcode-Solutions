//Time: O(n)
//Space: O(1)

//if current depth is <= half of max depth, the character goes to set 0, otherwise set 1
            

class Solution {
public:
    vector<int> maxDepthAfterSplit(string& s) {
        vector<int> v;
        int open = 0, d = 0;
        for(auto &c: s){
            if(c=='(')  open++;
            else if(c==')')  open--;

            d = max(d, open); //since a VPS is given, the no. of unmatched open brackets is the highest nesting depth
        }
        
        for(auto &c: s){
            if(c=='(')  open++;
            
            //if current depth is <= half of max depth, it goes to set 0, otherwise set 1
            if(open<=d/2)  v.push_back(0);
            else  v.push_back(1);

            if(c==')')  open--; //first assign set to closing bracket and then update curr depth
        }

        return v;

    }
};
