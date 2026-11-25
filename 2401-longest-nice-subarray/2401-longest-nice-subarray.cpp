class Solution {
public:
    int func(vector<int> &v)
    {
        for(int i=0;i<30;i++)
        if(v[i]>1)
        return 0;
        return 1;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int l=0;
        int r=0;
        vector<int> v(30);
        while(r<n)
        {
            for(int i=0;i<30;i++)
            {
                if((1<<i)&nums[r])
                v[i]++;
            }
            while(!func(v))
            {
                for(int i=0;i<30;i++)
                if((1<<i)&nums[l])
                v[i]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};