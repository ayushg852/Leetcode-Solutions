class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        vector<int> pref_gcd;
        for(int val:nums)
        {
            mx=max(mx, val);
            pref_gcd.push_back(gcd(val, mx));
        }
        sort(pref_gcd.begin(), pref_gcd.end());
        int l=0;
        int r=n-1;
        long long ans=0;
        while(l<r)
        {
            ans+= gcd(pref_gcd[l], pref_gcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};