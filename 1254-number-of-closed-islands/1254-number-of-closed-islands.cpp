class Solution {
public:
int m,n;
int valid(int i,int j,vector<vector<int>>& grid)
{
    if(i<0||j<0||i>=m||j>=n||grid[i][j]==1)
    return 0;
    return 1;
}
void dfs(int i,int j,vector<vector<int>>& grid)
{
    grid[i][j]=1;
    if(valid(i-1,j,grid))
    dfs(i-1,j,grid);
    if(valid(i+1,j,grid))
    dfs(i+1,j,grid);
    if(valid(i,j-1,grid))
    dfs(i,j-1,grid);
    if(valid(i,j+1,grid))
    dfs(i,j+1,grid);
}
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(valid(i,0,grid))
            dfs(i,0,grid);
            if(valid(i,n-1,grid))
            dfs(i,n-1,grid);
        }
        for(int j=1;j<n-1;j++)
        {
            if(valid(0,j,grid))
            dfs(0,j,grid);
            if(valid(m-1,j,grid))
            dfs(m-1,j,grid);
        }
        int ans=0;
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(valid(i,j,grid))
                {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};