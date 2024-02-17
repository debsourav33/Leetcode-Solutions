class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int far = 0;
        priority_queue<int, vector<int>, greater<int> > q;

        for(int i=1;i<heights.size();i++){
          int diff = heights[i] - heights[i-1];
          if(diff > 0){
            q.push(diff);

            ladders--; //try using ladder

            if(ladders>=0){ //ok if enough ladders available
              far = i;
            }
            else{ //if ladders run out, pick the smallest steep to climb using bricks
              bricks -= q.top();
              q.pop();
              //s.erase(s.begin());

              if(bricks>=0)  far = i;
              else  break;
            }
          }
          else{
            far = i;
          }         
        }

        return far;
    }
};
