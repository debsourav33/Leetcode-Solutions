/*
TC: O(sqrt(c))
SC: O(sqrt(c))
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        //generate all squared numbers between 0 and c
        vector<int> sqs = {0};
        for(int i=1; ;i++){
            //if( i*i < c) reformulate this to handle overflow 
            if(i <= c/i)  sqs.push_back(i*i);
            else  break;
        }

        //then perform 2 sum
        int i = 0, j = sqs.size()-1;
        
        while(i<=j){
            // reformulate these to handle overflow
            //if(sqs[i] + sqs[j] == c)  return true;
            //if(sqs[i] + sqs[j] < c)  i++;

            if(sqs[i] == c - sqs[j])  return true;
            if(sqs[i] < c - sqs[j])  i++;

            else  j--;
        }

        return false;
    }
};
