/*
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        if(nums.empty())  return {{lower,upper}};

        
        // edge case
        // completely out of bound
        if( upper < nums[0] || lower > nums[nums.size()-1]){
            return {{lower,upper}};
        }

        // boundary ranges
        // never happening (lower <= nums[i])
        if(lower<nums[0]){
            ans.push_back({lower,nums[0]-1});
        }
        
        // in-between ranges
        int last = lower;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < lower){
                continue; 
            }
            if(nums[i] > upper)  break;

            if(nums[i]-1 > nums[i-1] ){ //not consecutive? gap found!
                ans.push_back({nums[i-1] + 1, nums[i]-1});
            }
        }

        // boundary ranges
        if(upper > nums[nums.size()-1]){
            ans.push_back({nums[nums.size()-1] + 1,upper});
        }

        return ans;
    }
};
