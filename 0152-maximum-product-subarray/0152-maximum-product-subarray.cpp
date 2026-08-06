class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        nums.push_back(0);
        reverse(nums.begin(),nums.end());
        nums.push_back(0);
        int n=nums.size();
        vector<int> p(n,1);
        for(int i=1;i<n;i++)
        if(nums[i]!=0)
        p[i]=p[i-1]*nums[i];
        int i=0;
        int j=1;
        while(j<n)
        {
            while(j<n&&nums[j]!=0)
            j++;
            if(j>i+1)
            {
                ans=max(ans,p[j-1]/p[i]);
                for(int k=i+1;k<j;k++)
                {
                    if(k>i+1)
                    ans=max(ans,p[k-1]/p[i]);
                    if(k<j-1)
                    ans=max(ans,p[j-1]/p[k]);
                }
            }
            i=j;
            j++;
        }
        return ans;
    }
};