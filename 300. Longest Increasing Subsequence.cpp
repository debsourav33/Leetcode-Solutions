class Solution {

#define lefts 2*at
#define rights 2*at+1

public:
    struct SegTree{
      int n;
      vector<int> maxi;

      SegTree(int _n){
        n = _n;
        maxi = vector(4*n,0);
      }

      void update(int at, int l, int r, int pos, int val){
        if(l==r){
          maxi[at] = val;
          //cout<<l<<" "<<at<<" "<<val<<endl;
          return;
        }

        int mid = (l+r)/2;
        if(pos<=mid)  update(lefts, l, mid, pos, val);
        else  update(rights, mid+1, r, pos, val);

        maxi[at]= max(maxi[lefts],maxi[rights]);
      }

      int query(int at, int l, int r, int ql, int qr){
        if(ql<=l && r<=qr)  return maxi[at];
        if(qr<l || ql>r)  return 0;

        int mid = (l+r)/2;
        int x = query(lefts, l, mid, ql, qr);
        int y = query(rights, mid+1, r, ql, qr);

        return max(x,y);
      }
    };


    int lengthOfLIS(vector<int>& nums) {
      int max_val = 0;

      for(int &u: nums){
        u += 10004;  //offsetting for positive vals
        max_val = max(max_val+1, u);
      }

      SegTree t = SegTree(max_val+5);

      int ans = 0;
      for(int i=nums.size()-1;i>=0;i--){
        int val = nums[i];

        //the maximum of range (val+1, max_val) is the longest strictly sequence found at right-side of the array
        //for longest non-decreasing subseq, just query on range (val, max_val)
        int maxi = t.query(1,0,max_val,val+1,max_val);
        ans = max(ans, maxi+1);

        //update the current LIS starting from this index
        t.update(1,0,max_val,val,maxi+1);
      }

      return ans;

      

      return 0;

    }
};
