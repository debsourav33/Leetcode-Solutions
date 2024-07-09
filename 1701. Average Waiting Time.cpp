/*
Time: O(n)
Space: O(n)

Iterate on the customers maintaining current time
Check if a customer has to wait some time before his food is started being processed (initial wait time)
Then, the initial wait time + food processing time is his wait time
Calculate wait time for all customers and divide by n
*/
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& custs) {
        double curr_time = 0;
        double total = 0;
        double n = custs.size();

        for(auto &c: custs){
            double wait = 0;
            if(curr_time > c[0]){
                wait += curr_time - c[0]; //initial wait time before food processing
            }
            else{
                curr_time = c[0]; //otherwise, fast forward
            }  

            //we need c[1] time to prepare the order
            wait += c[1];
            curr_time += c[1]; 

            total += wait;
        }

        //get avg
        double avg = total/n;
        return avg; 
    }
};
