class Solution {
public:

    struct node{
      int sum, idx;

      node(int _sum, int _idx){
        sum = _sum;
        idx = _idx;
      }
    };

    friend bool operator<(node n1, node n2){
      return n1.sum < n2.sum;
    }

    int constrainedSubsetSum(vector<int>& v, int k) {
        //will store the max_sum and the corresponding index that the sum began with
        //which is basically dp memoization
        priority_queue<node> q;
        
        q.push(node(0,v.size()-1));
        
        int maxi = -1e9;

        for(int i=v.size()-1;i>=0;i--){
          int max_sum = q.top().sum, idx = q.top().idx; 
          
          //untill the top index of the heap is within i+k, pop() the queue
          while(idx-i > k){ 
            q.pop();
            max_sum = q.top().sum;
            idx = q.top().idx; 
          }

          //basically using memoized dp result here
          int max_sum_including_current_item = max(v[i] + max_sum, v[i]);  //either take only this item, or add it to the max_sum from an index within i+k

          maxi = max(max_sum_including_current_item, maxi);
          q.push(node(max_sum_including_current_item, i));
        }

        return maxi;
    }
};
