/*
Time: O(m*n)
Space: O(m*n) (dfs recursive space)

We use dfs -> maintaining current direction until we hit out-of-range or visited-cell, then we change direction in-order (right, down, left, up and then right again circularly)

*/
class Solution {
public:
    int m, n;
    vector<vector<int>> ret;
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; //right, down, left, up
    ListNode* head;

    void dfs(int r, int c, int d){ //d is current direction
        if(r<0 || r==m || c<0 || c==n)  return;
        if(ret[r][c] != -1)  return; //that serves the visiting array's job
        if(head == nullptr)  return;

        ret[r][c] = head->val; //assign the current node's value
        head = head->next; //advance current node to one node right 

        for(int i=0;i<4;i++){
            if(head == nullptr)  return;
            int dir_idx = (d + i)%4; //we go right, down, left, up => then right again in circular motion (thats why mod)

            //using dfs ensures we keep going the current direction until we hit out-of-bound/already visited node
            dfs(r+dir[dir_idx][0] , c+dir[dir_idx][1], dir_idx);
        }
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ret = vector(m, vector(n, -1)); //not reached array cells will have -1 as per instruction
        this->m = m;
        this->n = n;
        this->head = head;

        dfs(0,0,0);

        return ret;

    }
};
