/*
Time: O(n)
Space: O(n)

Intuition:

For a number x, we can take any y to pair with if (x+y)%k == 0 greedily, we dont have to worry about another number z needing y to pair with, because if x has another matching partner, it will surely match with z

since if, (x+y)%k = (z+y)%k
    =>  x % k = z % k

So have the modular (by k) of each number in a map, and for every number check if the needed number has still a positive count the map (if so, decrement the count and move along)

Important: For negative, take it's positive equivalence

edge case: if an element is equal to its partner, we need to check if the count is even
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;

        for(auto &u: arr){
            u = ((u%k)+k)%k; //shift to positive (with reference, so it changes in place)
            //now u is positive and smaller than k
            cnt[u]++; //
            //cout<<(u)<<" "<<cnt[u%k]<<endl;        
        }
        
        for(auto u: arr){
            int need = (k - u) % k; //u is positive and smaller than k
            //cout<<u<<" "<<need<<" "<<cnt[u%k]<<endl;        

            //edge case: if an element is equal to its partner, we need to check if the count is even
            if(u == need)  if(cnt[u]%2 == 1)  return false;
            //otherwise, the count of u and its partner need to be equal
            if(cnt[u] != cnt[need])  return false; 
        }

        return true;
    }
};
