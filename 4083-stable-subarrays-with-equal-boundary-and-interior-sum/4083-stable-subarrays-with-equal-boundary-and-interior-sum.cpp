class Solution {
public:
    long long countStableSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<long long> p(n+1);
        for(int i=0;i<n;i++)
        p[i+1]=p[i]+arr[i];
        map<pair<long long,long long>,long long> m;
        long long ans=0;
        for(int r=2;r<n;r++)
        {
            int l=r-2;
            m[{arr[l],p[l+1]+arr[l]}]++;
            ans += m[{arr[r],p[r]}];
        }
        return ans;
    }
};