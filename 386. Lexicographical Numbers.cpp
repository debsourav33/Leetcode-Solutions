/*
Time: O(n)
Space: O(log10(n))  (recursive stack space)

Constructive Algorithm:
Build the numbers in the sorted order. With recursive calls, start from the smallest number, and appending one more digit (smallest to largest in order) to the LSD.
*/


class Solution {
public:
    int n;
    vector<int> ret;
    void call(int val){
        if(val>n)  return;
        ret.push_back(val);

        //appending one more digit (smallest to largest in order) to the LSD.
        for(int i=0;i<=9;i++){
            call(val*10+i);
        }
    }

    vector<int> lexicalOrder(int n) {
        this->n = n;

        //starting from smallest to largest
        for(int i=1;i<=9;i++)  call(i);

        return ret;
    }
};
