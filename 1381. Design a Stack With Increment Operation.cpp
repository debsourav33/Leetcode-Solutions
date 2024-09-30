/*
Time: O(1) all_operation
Space: O(n)

The increment is applied for bottom-most elements, and their bottom depth don't change by new push/pops (until, ofcourse, they get popped themselves)

So we can maintain how much values to be incremented for which bottom-depth
When we are popping a value having this bottom-depth, we can add the corresponding increment value stored for that depth. 

Then, add the increment value for this depth to that of depth-1 (if we have one increment operation x for k bottom elements, we have the same x increment for k-1 bottom values as well) and make the increment value 0 for this depth and 
*/

class CustomStack {
public:
    unordered_map<int, int> inc;
    stack<int> st;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxSize)
            st.push(x);
    }
    
    int pop() {
        if(st.empty())  return -1;

        int ret = st.top() + inc[st.size()]; //add the corresponding increment value stored for that depth. 
        inc[st.size()-1] += inc[st.size()]; //add the increment value for this depth to that of depth-1 (if we have one increment operation x for k bottom elements, we have the same x increment for k-1 bottom values as well) and make the increment value 0 for this depth and

        inc[st.size()] = 0;
        st.pop();

        return ret;
    }
    
    void increment(int k, int val) {
        //maintain how much values to be incremented for which bottom-depth
        k = min(k, (int) st.size());
        inc[k] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
