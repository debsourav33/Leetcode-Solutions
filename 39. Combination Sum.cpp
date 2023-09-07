class Solution {
public:
    vector<int> combo, nums;
    vector<vector<int>> answer;
    int len,target;

    void call(int pos, int sum){
      if(sum>target)  return;
      if(sum==target){
        answer.push_back(combo);
        return;
      }

      for(int i=pos;i<len;i++){
        sum+= nums[i];
        combo.push_back(nums[i]);

        call(i, sum); //same element can be picked again until sum exceeds target

        sum-= nums[i];
        combo.pop_back();
      }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int tar) {
        answer.clear();
        
        nums = candidates;
        len = candidates.size();
        target = tar;


        call(0,0);
        return answer;
        
    }
};
