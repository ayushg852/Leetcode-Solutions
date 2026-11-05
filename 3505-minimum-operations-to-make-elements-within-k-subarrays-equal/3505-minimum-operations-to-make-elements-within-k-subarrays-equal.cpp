class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        vector<long long> op(n);
        multiset<int> s1(nums.begin(),nums.begin()+x),s2;
        long long sum1=accumulate(nums.begin(),nums.begin()+x,0LL);
        long long sum2=0;
        for(int i=1;i<=x/2;i++)
        {
            int a=*(s1.rbegin());
            sum1-=a;
            sum2+=a;
            s2.insert(a);
            s1.erase(prev(s1.end()));
        }
        op[x-1]=x%2==0?sum2-sum1:sum2-sum1+(*s1.rbegin());
        for(int i=x;i<n;i++)
        {
            int to_remove=nums[i-x];
            int to_add=nums[i];
            auto it=s1.find(to_remove);
            if(it!=s1.end())
            {
                s1.erase(it);
                sum1-=to_remove;
            }
            else
            {
                it=s2.find(to_remove);
                s2.erase(it);
                sum2-=to_remove;
            }
            if(s1.empty())
            {
                if(to_add<=(*s2.begin()))
                {
                    s1.insert(to_add);
                    sum1+=to_add;
                }
                else
                {
                    s2.insert(to_add);
                    sum2+=to_add;
                }
            }
            else if(to_add<=(*s1.rbegin()))
            {
                s1.insert(to_add);
                sum1+=to_add;
            }
            else
            {
                s2.insert(to_add);
                sum2+=to_add;
            }
            if(s1.size()>s2.size()+1)
            {
                int a=*s1.rbegin();
                s2.insert(a);
                s1.erase(prev(s1.end()));
                sum1-=a;
                sum2+=a;
            }
            if(s2.size()>s1.size())
            {
                int a=*s2.begin();
                s1.insert(a);
                s2.erase(s2.begin());
                sum1+=a;
                sum2-=a;
            }
            op[i]=x%2==0?sum2-sum1:sum2-sum1+(*s1.rbegin());
        }
        long long INF=LLONG_MAX/4;
        vector<vector<long long>> dp(n,vector<long long>(k+1,INF));
        for(int i=0;i<n;i++)
        dp[i][0]=0;
        for(int i=x-1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                long long take=INF;
                if(j==1)
                take=op[i];
                else if(i-x>=0)
                take=op[i]+dp[i-x][j-1];
                long long skip=(i>0?dp[i-1][j]:INF);
                dp[i][j]=min(take,skip);
            }
        }
        return dp[n-1][k];
    }
};