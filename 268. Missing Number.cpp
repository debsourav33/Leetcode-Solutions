class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //nums contains values (0,n) inclusive
        //to accomodate the missing value, add a placeholder
        nums.push_back(1e4+4);


        for(int i=0;i<nums.size()-1;i++){
          //for a value k, mark (k-1)th index to be negative
          //so that for every value present, its corresponding index has been marked negative
          //Important: to deal with 0, we add an offset of 1
          int original_value = nums[i] >= 0 ? nums[i] : (nums[i] * -1) - 1;
          nums[original_value] = (nums[original_value] + 1) * -1;
        }

        for(int i=0;i<nums.size();i++){
          //if any index is not marked negative, we know the corresponding value is missing
          if(nums[i] >= 0)  return i;
        }

        return -1; //will never reach
    }
};
