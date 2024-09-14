/*
Time: O(n)
Space: O(n)

We can not have a better AND of subarray than the maximum number itself (AND can't produce 1 bit in the product if it's already not there)

So our problem is reformulated to finding the maximum element, and the longest subarray where all elements == max_element
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = -1, longest = 0, streak = 0;

        //finding the maximum element, and the longest subarray where all elements == max_element
        for(auto num: nums){
            if(num > maxi){
                maxi = num;
                longest = streak = 1; //fix: when new maxi found, longest_streak = current_streak should be 1

            }
            else if(num == maxi){
                streak++;
            }
            else{
                streak = 0;
            }

            longest = max(longest, streak);
        }

        return longest;
    }
};
