class Solution {
public:
    vector<int> v;
    int n;
    
    int diff = INT_MAX;
    int best = -1;


    void twoSum(int st, int endi, int add, int target){
      while(st<endi){
        int sum = add + v[st] + v[endi];
        //cout<<sum<<endl;

        if(abs(target - sum) < diff){
          diff = abs(target -sum);
          best = sum;
        }

        if(sum <= target)  st++;
        else  endi--;
      }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        v = nums;
        sort(v.begin(),v.end());
        diff = INT_MAX;
        n = nums.size();

        for(int i=0;i<n;i++)  twoSum(i+1,n-1,v[i],target);
        return best;
    }
};
