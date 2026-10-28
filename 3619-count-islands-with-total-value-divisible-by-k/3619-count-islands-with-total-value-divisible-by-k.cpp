class Solution {
public:
int m,n;
long long s;
vector<vector<int>> vis;
int valid(int i,int j,vector<vector<int>>& grid)
{
    if(i<0||j<0||i>=m||j>=n||grid[i][j]==0||vis[i][j]==1)
    return 0;
    return 1;
}
void dfs(int i,int j,vector<vector<int>>& grid)
{
    vis[i][j]=1;
    s+=grid[i][j];
    if(valid(i-1,j,grid))
    dfs(i-1,j,grid);
    if(valid(i+1,j,grid))
    dfs(i+1,j,grid);
    if(valid(i,j-1,grid))
    dfs(i,j-1,grid);
    if(valid(i,j+1,grid))
    dfs(i,j+1,grid);
}
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vis.resize(m,vector<int>(n));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(valid(i,j,grid))
                {
                    s=0;
                    dfs(i,j,grid);
                    if(s%k==0)
                    ans++;
                }
            }
        }
        return ans;
    }
};