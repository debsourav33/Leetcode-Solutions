class Solution {
public:
    vector<int> zero_indices;

    //returns farthest left we can afford to go when we have encounter zeroes 0 and max k flips allowed
    int farthest(int zeroes, int k){
        int no = zeroes - k;
        int idx = no > 0 ? zero_indices[no-1] : -1; //if k>=zeroes, we can flip all the way left!

        return idx;
    }

    int longestOnes(vector<int>& v, int k) {
        int zeros = 0;
        int ans = 0;
        zero_indices.clear();


        for(int i=0; i<v.size(); i++){
            if(v[i]==0)  zeros += 1, zero_indices.push_back(i);

            int farthest_zero = farthest(zeros, k); 
            //cout<<i<<" "<<farthest_zero<<endl;
            //printf("zeroes found: %d\n",zeros);

            int contiguous = i - farthest_zero;
            ans = max(ans, contiguous);
        }

        return ans;
    }
};