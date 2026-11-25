class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int ans=0;
        int l=0;
        int r=0;
        int cur_cost=0;
        while(r<n)
        {
            cur_cost+=abs(t[r]-s[r]);
            while(cur_cost>maxCost)
            cur_cost-=abs(t[l]-s[l++]);
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};