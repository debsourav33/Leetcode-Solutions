class Solution {
public:
    const static int N = 5e5+4;
    int sum[4*N], lazy[4*N];

    #define lefts (2*at)
    #define rights (2*at+1)

    void merge(int at){
      sum[at] = sum[lefts] + sum[rights];
    }

    void build(int at, int l, int r){
      if(l==r){
        sum[at] = 0;
        return;
      }

      int mid = (l+r)/2;
      build(lefts, l, mid);
      build(rights, mid+1, r);
      merge(at);
    }

    void upd(int at, int x){
      sum[at] += x;
      lazy[at] += x;
    }

    void propagate(int at){
      upd(lefts, lazy[at]);
      upd(rights, lazy[at]);

      lazy[at] = 0;
    }

    void update(int at, int l, int r, int ql, int qr){
      if(r<ql || l>qr)  return;
      if(ql<=l && r<=qr){
        sum[at]++;
        lazy[at]++;
        return;
      }

      propagate(at);

      int mid = (l+r)/2;
      update(lefts, l, mid, ql, qr);
      update(rights, mid+1, r, ql, qr);
      merge(at);
    }

    int query(int at, int l, int r, int index){
      if(l==r)  return sum[at];

      propagate(at);

      int mid = (l+r)/2;

      if(index<=mid)  return query(lefts, l, mid, index);
      return query(rights, mid+1, r, index);
    }


    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
      //compress array
      vector<int> a;
      for(auto v: flowers){
        a.push_back(v[0]);
        a.push_back(v[1]);
      }
      for(auto p: people){
        a.push_back(p);
      }

      sort(a.begin(),a.end());
      //the '&' sign is important if we wanna mutate vector content
      for(auto &v: flowers){
        int v0 = lower_bound(a.begin(),a.end(), v[0]) - a.begin();
        int v1 = lower_bound(a.begin(),a.end(), v[1]) - a.begin();
        
        v[0] = v0;
        v[1] = v1;

        
      }
      for(auto &p: people){
        int p0 = lower_bound(a.begin(),a.end(), p) - a.begin();
        p = p0;
      }

      vector<int> ret;
      int n = 500005;
      
      build(1,0,n-1);

      for(auto v: flowers){
        update(1,0,n-1,v[0],v[1]);
      }

      for(auto p: people){
        int sum = query(1,0,n-1,p);
        //printf("q %d\n",p);
        ret.push_back(sum);
      }

      return ret;
    }
};
