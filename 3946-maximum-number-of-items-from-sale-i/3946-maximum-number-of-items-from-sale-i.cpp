class Solution {
public:
    int min_price=1e6;
    int func(int i,int budget,vector<pair<int,int>> &multiples,vector<vector<int>> &dp)
    {
        if(budget<0)
        return -1e9;
        if(i<0)
        return budget/min_price;
        if(dp[i][budget]!=-1)
        return dp[i][budget];
        int ans=func(i-1,budget,multiples,dp);
        if(budget>=multiples[i].second)
        ans=max(ans,multiples[i].first+func(i-1,budget-multiples[i].second,multiples,dp));
        return dp[i][budget]=ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int max_factor=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            max_factor=max(max_factor,items[i][0]);
            freq[items[i][0]]++;
            min_price=min(min_price,items[i][1]);
        }
        vector<vector<int>> all_multiples(max_factor+1);
        for(int i=1;i<=max_factor;i++)
        {
            for(int j=i;j<=max_factor;j+=i)
            all_multiples[i].push_back(j);
        }
        vector<pair<int,int>> multiples;
        for(int i=0;i<n;i++)
        {
            int c=1;
            for(auto &x:all_multiples[items[i][0]])
            {
                if(freq.count(x))
                {
                    if(x==items[i][0])
                    c+=freq[x]-1;
                    else
                    c+=freq[x];
                }
            }
            multiples.push_back({c,items[i][1]});
        }
        vector<vector<int>> dp(n,vector<int>(budget+1,-1));
        return func(n-1,budget,multiples,dp);
    }
};