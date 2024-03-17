class FreqStack {
public:
    unordered_map<int,int> freq;
    

    /*
    Technically, the problem is asking for a priority_queue, not a stack
    Where priority is defined by frequency, and tie is broken by timestamp
    */

    //pq node: value, frequency (at the time of insertion), time of insertion
    priority_queue<vector<int>, vector<vector<int>>, decltype([](vector<int> &v1, vector<int> &v2){
        if(v1[1] == v2[1])  return v1[2] < v2[2];
        return v1[1] < v2[1];
    })> pq;
    int t = 0;

    FreqStack() {
    }
    
    void push(int val) {
        freq[val] = freq.count(val) ? freq[val]+1 : 1;
        pq.push({val,freq[val],t});

        t++;
    }
    
    int pop() {
        int top = pq.top()[0];
        pq.pop();

        freq[top]--;

        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
