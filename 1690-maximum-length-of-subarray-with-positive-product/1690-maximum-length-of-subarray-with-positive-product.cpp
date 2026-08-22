class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        nums.push_back(0);
        reverse(nums.begin(),nums.end());
        nums.push_back(0);
        int n=nums.size();
        int ans=0;
        int i=0;
        int j=1;
        while(j<n)
        {
            while(j<n&&nums[j]!=0)
            j++;
            if(j>i+1)
            {
                int c=0;
                int first=-1;
                int last=-1;
                for(int k=i+1;k<j;k++)
                {
                    if(nums[k]<0)
                    {
                        c++;
                        if(first==-1)
                        first=k;
                        last=k;
                    }
                }
                if(c%2==0)
                ans=max(ans,j-i-1);
                else
                ans=max(ans,max(j-first-1,last-i-1));
            }
            i=j;
            j++;
        }
        return ans;
    }
};