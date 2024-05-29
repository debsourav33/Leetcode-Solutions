/*
Time: O(n)
Space: O(n)

Keep frequency map freq
Iterate from i=n to 1 and for atmost k times, whenever we get a value for freq[i], we know its inside k-most frequent
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        const int N = 100001, MAXN = 10001;
        int count[2*MAXN];
        vector<int> freq[N];

        memset(count,0,sizeof(count));

        //create freq map
        for(int i=0;i<nums.size();i++){
          int positive_val = nums[i] + MAXN; //offset into positive
          ++count[positive_val];
        } 

        for(int i=0;i<2*MAXN;i++){
          int cnt = count[i];
          if(cnt)
            freq[cnt].push_back(i); 
        }   


        //iterated backwards so more freq items come first!
        for(int i=nums.size();i>0;i--){
          for(int val: freq[i]){
            int original_value = val - MAXN; //get original removing offset
            ret.push_back(original_value);
            
            if(ret.size()>=k)  return ret; //k freq items reached
          }
          
        }

        return {}; //will never be reached
    }
};
