class Solution {
public:
    
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
       int ans = 0;
       int prod = 1;
       int left_border = 0;

       for(int i=0;i<v.size();i++){
         prod *= v[i];
         
         //left_border can move O(n) times across all iteration of for loop
         //so, the cumulative runtime is O(n)
         while(prod >= k && left_border <= i){  
           prod /= v[left_border];
           left_border++; //squeezing from left until product becomes < k
         }

         ans += i - left_border + 1;  //no. of elements can be multiplied together on the left from i

       }

       return ans;

    }
};
