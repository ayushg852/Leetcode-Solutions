class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans(n-k+1);
        vector<int> freq(50);
        for(int i=0;i<k;i++)
        if(nums[i]<0)
        freq[-nums[i]-1]++;
        int c=0;
        for(int i=49;i>=0;i--)
        {
            if(c+freq[i]>=x)
            {
                ans[0]=-(i+1);
                break;
            }
            c+=freq[i];
        }
        for(int i=1;i<=n-k;i++)
        {
            if(nums[i-1]<0)
            freq[-nums[i-1]-1]--;
            if(nums[i+k-1]<0)
            freq[-nums[i+k-1]-1]++;
            c=0;
            for(int j=49;j>=0;j--)
            {
                if(c+freq[j]>=x)
                {
                    ans[i]=-(j+1);
                    break;
                }
                c+=freq[j];
            }
        }
        return ans;
    }
};