class Solution {
public:
using ll=long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(costBoth>=cost1+cost2)
        return 1LL*cost1*need1+1LL*cost2*need2;
        ll a=min(need1,need2);
        ll ans=a*costBoth;
        need1-=a;
        need2-=a;
        ans+=1LL*need1*min(cost1,costBoth);
        ans+=1LL*need2*min(cost2,costBoth);
        return ans;
    }
};