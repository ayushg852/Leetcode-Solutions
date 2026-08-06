class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> p(n);
        p[0]=nums[0];
        vector<int> s(n);
        s[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        p[i]=p[i-1]*nums[i];
        for(int i=n-2;i>=0;i--)
        s[i]=s[i+1]*nums[i];
        vector<int> ans(n);
        ans[0]=s[1];
        ans[n-1]=p[n-2];
        for(int i=1;i<n-1;i++)
        ans[i]=s[i+1]*p[i-1];
        return ans;
    }
};