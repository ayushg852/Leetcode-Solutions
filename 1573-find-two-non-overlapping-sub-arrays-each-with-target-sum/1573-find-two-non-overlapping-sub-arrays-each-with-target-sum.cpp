class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l=0;
        int n=arr.size();
        int r=0;
        int s=0;
        vector<pair<int,int>> v;
        while(r<n)
        {
            s+=arr[r];
            while(l<=r&&s>target)
            {
                s-=arr[l++];
            }
            if(s==target)
            {
                v.push_back({l,r});
            }
            r++;
        }
        int nn=n;
        n=v.size();
        if(n<2)
        return -1;
        vector<int> sm(n,v[n-1].second-v[n-1].first+1);
        for(int i=v.size()-2;i>0;i--)
        sm[i]=min(sm[i+1],v[i].second-v[i].first+1);
        int ans=2*nn+5;
        for(int i=0;i<n-1;i++)
        {
            int j=upper_bound(v.begin()+i+1,v.end(),make_pair(v[i].second,nn))-v.begin();
            if(j<n)
            ans=min(ans,v[i].second-v[i].first+1+sm[j]);
        }
        if(ans==2*nn+5)
        return -1;
        return ans;
    }
};