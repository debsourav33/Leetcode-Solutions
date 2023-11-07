class Solution {
public:
    int ceil_div(int a, int b){
      return (a-1)/b+1;
    }
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
      int n = dist.size();
      vector<int> times;

      //time needed for monster i to reach the city is
      //ceiling of dist/speed
      for(int i=0;i<n;i++)    
        times.push_back(ceil_div(dist[i],speed[i]));

      sort(times.begin(),times.end());
      
      int cnt = 0;
      int currTime = 0;

      //how many can we get if we take one unit of more currTime to shoot one monster
      for(auto time: times){
        if(currTime < time){
          cnt++;
          currTime++;
        }
        else{
          break;
        }
      }

      return cnt;

    }
};
