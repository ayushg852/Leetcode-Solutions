class Solution {
public:
long long func(int i,int n,vector<long long> &dp,vector<int> &costs)
{
    if(i>=n)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    long long a=1+costs[i]+func(i+1,n,dp,costs);
    if(i+1<n)
    a=min(a,4+costs[i+1]+func(i+2,n,dp,costs));
    if(i+2<n)
    a=min(a,9+costs[i+2]+func(i+3,n,dp,costs));
    return dp[i]=a;
}
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1,-1);
        return func(0,n,dp,costs);
    }
};