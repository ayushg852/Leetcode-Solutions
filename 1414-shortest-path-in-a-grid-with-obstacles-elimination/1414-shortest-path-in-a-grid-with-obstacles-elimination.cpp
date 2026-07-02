class Solution {
public:
int m,n;
queue<vector<int>> q;
vector<vector<vector<int>>> d;
void func(int old_i,int old_j,int new_i,int new_j,int old_k,int k,vector<vector<int>>& grid)
{
    if(new_i<0||new_i>=m||new_j<0||new_j>=n)
    return;
    int new_k=old_k+grid[new_i][new_j];
    if(new_k>k||d[new_i][new_j][new_k]!=1e8)
    return;
    d[new_i][new_j][new_k]=d[old_i][old_j][old_k]+1;
    q.push({new_i,new_j,new_k});
}
    int shortestPath(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        d.assign(m,vector<vector<int>> (n,vector<int>(k+1,1e8))); 
        q.push({0,0,0});
        d[0][0][0]=0;
        while(!q.empty())
        {
            int old_i=q.front()[0];
            int old_j=q.front()[1];
            int old_k=q.front()[2];
            q.pop();
            func(old_i,old_j,old_i-1,old_j,old_k,k,grid);
            func(old_i,old_j,old_i+1,old_j,old_k,k,grid);
            func(old_i,old_j,old_i,old_j-1,old_k,k,grid);
            func(old_i,old_j,old_i,old_j+1,old_k,k,grid);
        }
        int ans=1e8;
        for(int i=0;i<=k;i++)
        ans=min(ans,d[m-1][n-1][i]);
        if(ans==1e8)
        return -1;
        return ans;
    }
};