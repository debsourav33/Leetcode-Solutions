/*
Time: O(n)
Space: O(1)

*/

class Solution {
public:

    // how to get an intersecton?
    // the range between bigger of the starting point and smaller of the ending point
    vector<int> getInter(vector<int> &v1, vector<int> &v2){
        int st = max(v1[0],v2[0]);
        int endi = min(v1[1],v2[1]);

        // do they overlap?
        if(st<=endi)  return {st,endi};
        return {};
    }


    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int i = 0, j = 0;
        int n1 = f.size(), n2 = s.size();
        vector<vector<int>> ret;

        while(i<n1 && j<n2){
            
            // get the intersection
            vector<int> inter = getInter(f[i], s[j]);

            if(inter.size())  ret.push_back(inter);

            //whichever has smaller ending point, move that pointer
            if(f[i][1] < s[j][1]) i++;
            else  j++;
        }

        return ret;


    }
};
