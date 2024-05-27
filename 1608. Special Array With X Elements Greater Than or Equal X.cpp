/*
Time: O(nlogn)
Space: O(1)

Sort the array
For every index, check if the items bigger than it ( = cnt) is smaller or equal to current element and bigger than previous element (if exist)
in that case, cnt is the ans
if no suce cnt exist, return -1
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int ans;
        int cnt = 0;
        for(int i=nums.size()-1;i>=0;i--){
            cnt++;
            
            //check if the items bigger than it ( = cnt) is smaller or equal to current element and bigger than previous element (if exist)
            if(i>0 && nums[i] >= cnt && nums[i-1] < cnt)  return cnt;
            //if previous element doesnt exist, we simply check the current element
            if(i==0 && nums[i] >= cnt )  return cnt;
        }

        return -1;
    }
};
