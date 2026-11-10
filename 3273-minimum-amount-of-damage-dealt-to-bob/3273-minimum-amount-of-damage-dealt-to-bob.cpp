class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n=damage.size();
        vector<pair<int,int>> v(n);
        long long s=0;
        for(int i=0;i<n;i++)
        {
            s+=damage[i];
            int a=ceil((double)health[i]/power);
            v[i]={damage[i],a};
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            if(1LL*a.first*b.second==1LL*a.second*b.first)
            return a.second<b.second;
            return 1LL*a.first*b.second>1LL*a.second*b.first;
        });
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=s*v[i].second;
            s-=v[i].first;
        }
        return ans;
    }
};