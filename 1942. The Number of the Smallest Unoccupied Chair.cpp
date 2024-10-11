/*
Time: O(nlogn)
Space: O(n)

Similar Approach to Meeting Room III

Maintain a priority queue (booked) of min-heap (chair id, booked until) based on the booked until time and maintain an available set of chair

Sort the times array and traverse one by one
- While traversing first check the which of the booked chairs are free now (by comparing the booked_until time in booked queue and the arrival time of that friend and push them back to available
- Then pick the lowest chair from the available set 
- Assign it to that friend and push it to the booked queue
*/


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<vector<int>> orig = times;
        sort(times.begin(), times.end());

        int target = -1;
        for(int i=0;i<n;i++){
            if(times[i][0] == orig[targetFriend][0]){
                target = i;
                break;
            }
        }

        cout<<target<<endl;

        //room id, ending time
        auto cmp = [](vector<int> &v1, vector<int> &v2){
            if(v1[1] == v2[1])  return v1[0] > v2[0];
            return v1[1] > v2[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> booked(cmp);
        set<int> available;

        for(int i=0;i<n;i++)  available.insert(i);

        for(int i=0;i<n;i++){
            while(!booked.empty() && booked.top()[1] <= times[i][0]){
                vector<int> top = booked.top();
                available.insert(top[0]);
                booked.pop();
            }

            //find the first (lowest) available chair
            int chair = *(available.begin());
            if(i==target)  return chair; //target friend?

            //this chair is going to be assigned to this friend
            //remove this from available chairs and push to booked queue
            available.erase(chair);
            booked.push({chair,times[i][1]});
        }


        return 0;
    }
};
