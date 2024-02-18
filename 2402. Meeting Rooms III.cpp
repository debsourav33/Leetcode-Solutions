class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        vector<int> cnt(n,0);

        //min-heap for available rooms
        //holds room id and booked-until time
        //sorted by room id
        priority_queue<vector<long long>, vector<vector<long long>>, decltype([](vector<long long>& v1, vector<long long>& v2){
          return v1[0] > v2[0];
        })> available;

        //min-heap for booked rooms
        //holds room id and booked-until time
        //sorted by booked-until time, tied broken by smaller room id
        priority_queue<vector<long long>, vector<vector<long long>>, decltype([](vector<long long>& v1, vector<long long>& v2){
          if(v1[1]==v2[1])  return v1[0] > v2[0];
          return v1[1] > v2[1];
        })> booked;

        
        sort(m.begin(), m.end(), [](vector<int>& v1, vector<int>& v2){
          return v1[0] < v2[0];
        });

        for(int i=0;i<n;i++) available.push({i,-1});

        
        for(int i=0;i<m.size();i++){
          int t = m[i][0];
          
          //Make all the booked rooms that are freed at or before time t enter available queue
          //this runs O(2*m) cumulative time
          //since maximum m booking and unbooking can happen
          while(!booked.empty()){
            auto v = booked.top();

            if(v[1] > t){
              break;
            }
            
            available.push(v);
            booked.pop();
          }

          //if a room is available, pick the first room (with lowest id) and put in booked
          if(!available.empty()){
            auto v = available.top();
            available.pop();

            cnt[v[0]]++;
            booked.push({v[0], m[i][1]});
          }
          else{ //else pick one booked room with the shortest end time and resrever it for (endTime to endTime+duration)
            auto v = booked.top();
            booked.pop();

            cnt[v[0]]++;
            booked.push({v[0], v[1] + m[i][1] - m[i][0]});
          }          
        }

        //which room was used most?
        int ans = 0;
        for(int i=1;i<n;i++){
          if(cnt[i] > cnt[ans])  ans = i;
        }

        return ans;
    }
};
