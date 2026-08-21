class Solution {
public:
using ll=long long;
    ll less_than_equal(vector<ll>& v1,vector<ll>& v2,ll m)
    {
         __int128 ans=0;
        for(ll x:v1)
        ans+=m/x;
        for(ll x:v2)
        ans-=m/x;

        if(ans>LLONG_MAX)
        return LLONG_MAX;
        if(ans<LLONG_MIN)
        return LLONG_MIN;
        return (ll)ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        vector<ll> v1,v2;
        int n=coins.size();
        int N=1<<n;
        for(int mask=1;mask<N;mask++)
        {
            ll l=1;
            int c=0;
            for(int i=0;i<n;i++)
            {
                if((1<<i) & mask)
                {
                    ll g=gcd(l,(ll)coins[i]);
                    __int128 nl=(__int128)(l/g)*coins[i];
                    if(nl>LLONG_MAX)
                    {
                        l=LLONG_MAX;
                    }
                    else
                    {
                        l=(ll)nl;
                    }
                    c++;
                }
            }
            if(l==LLONG_MAX)
            continue;
            if(c%2==0)
            v2.push_back(l);
            else
            v1.push_back(l);
        }
        // for(auto x:v1)
        // cout<<x<<" ";
        // cout<<endl;
        // for(auto x:v2)
        // cout<<x<<" ";
        // cout<<endl;
        ll l=1;
        ll r=1LL*k*(*min_element(coins.begin(),coins.end()));
        ll ans=r;
        while(l<r)
        {
            ll m=l-(l-r)/2;
            ll t=less_than_equal(v1,v2,m);
            // cout<<m<<" "<<t<<endl;
            if(t>=k)
            r=m;
            else
            l=m+1;
        }
        return l;
    }
};