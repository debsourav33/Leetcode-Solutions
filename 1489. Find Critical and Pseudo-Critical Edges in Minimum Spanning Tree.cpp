#define fr(n) for(int i=0;i<n;i++)

class Solution {
public:
    int n, m;
    vector<int> order;
    vector<int> par;
    vector<vector<int>> edges;

    int find(int x){
      if(par[x]==x)  return x;

      return par[x] = find(par[x]);
    }

    int unions(int x, int y){
      int p1 = find(x), p2 = find(y);

      if(p1==p2)  return -1;
      par[p2] = p1;

      return 0;
    }
    
    //@Params
    // skip: skip this edge and see if the mst is bigger than shortest (-> critical edge)
    // must: must take this edge and see if the mst remains same (-> pseudo critical edge)
    int mst(int skip, int must){
      par.clear();
      fr(n)  par.push_back(i);
      
      int total = 0, taken = 0;

      if(must!=-1)  {
        unions(edges[must][0],edges[must][1]);
        total += edges[must][2];
        taken++;
      }

      fr(m){
        int pos = order[i];
        if(pos==skip || pos == must)  continue;

        int u = edges[pos][0], v = edges[pos][1], w = edges[pos][2];

        if(unions(u,v) != -1){
          taken ++;
          total+= w;
        }

        if(taken==n-1)  return total;
      }

      return -1;
    }


    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
      this->n = n;
      this->m = edges.size();
      this->edges = edges;
      
      fr(m) order.push_back(i);

      sort(order.begin(),order.end(),[edges](int x, int y){
        return edges[x][2] < edges[y][2];
      });

      int shortest = mst(-1,-1);
      vector<int> critical, pseudo;

      fr(m){
        int alter = mst(i,-1);

        // -1 means we couldn't form a tree skipping the edge
        // alter > shortest means without this edge we can't have shortest mst (critical)
        if(alter==-1 || alter > shortest)  critical.push_back(i);
        else{
          alter = mst(-1,i);

          // if mst remains same by brutefully taking this edge, than this non-critical edge is pseudo-critical
          if(alter==shortest)  pseudo.push_back(i);
        }
      }


      return {critical, pseudo};
    }
};
