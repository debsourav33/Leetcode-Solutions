class Solution {
public:
    
    //O(n) time, o(1) space (changing the input vector)
    int firstMissingPositive(vector<int>& v) {
        v.push_back(0);  //we need 0 at 0th position, so even if it's not there, just push it
        int n = v.size();

        for(int i=0;i<n;i++){
            int num = v[i];
            if(num>=n)  continue;

            //This while loop can run a total of n times for the entire For loop
            //it just places each element num to (num-1) position
            //transfer the current item num to v[num] index, and bring the v[num] item to this index
            //now this index holds v[num] 
            //repeat the process again until current index i holds either value = i or a value out of range
            while(num>=0 && num<n && v[num]!=num){
                //cout<<num<<endl;
                
                int tmp = v[num];
                v[num] = num;
                v[i] = tmp;

                num = tmp;
                //cout<<"now: "<<num<<endl;
            }
        }


        //the vector should be like v[0] = 1, v[1] = 2... v[i] = i+1 ... if, for any index i, it doesn't, then the value i+1 is missing
        int last = 0; 
        for(int i=1;i<n;i++){
            if(v[i]==i)  last = i;
            else  return i;           
        }

        return last+1;
    }
};
