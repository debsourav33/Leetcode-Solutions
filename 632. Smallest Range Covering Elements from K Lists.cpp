class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      int n = nums.size();
      int offset = 100000;

      vector<int> cnt(n,0);
      vector<int> m[2000001];
      //for(int i=-100000;i<=100000;i++)  m[i] = {};

      for(int i=0;i<n;i++){
        for(auto &num: nums[i]){
          num += offset;
        }
      }

      for(int i=0;i<n;i++){
        for(auto num: nums[i]){
          m[num].push_back(i);  //m[num] contains idx of groups that have an element = num
        }
      }

      int score = 0;
      int last = 0;

      int min_range = 200000;
      int start = -100000;

      //the current range is (last --> i)
      for(int i=000000;i<=200000;i++){
        for(auto id: m[i]){  //we incremented the range, so lets see if we got more values covered
          cnt[id]++;
          if(cnt[id]==1)  score++; //if the covered value is first for its group, increment score
        }

        if(score<n)  continue;

        while(score>=n){
          //shrink the window from left as long as score is >= n
          last++;
          for(auto id: m[last-1]){  //we just move the range past (last-1)
            cnt[id]--;
            if(cnt[id]==0)  score--;  //if the just passed value was the last for its group, decrement score
          }
        }

        //we ended at one position right to where score is >= n
        int range = i - (last-1);

        if(range<min_range){
          min_range = range;
          start = last-1;

          //cout<<start<<" "<<start+range<<endl;
        }
      }

      start = start-offset;
      return {start, start+min_range};

    }
};
