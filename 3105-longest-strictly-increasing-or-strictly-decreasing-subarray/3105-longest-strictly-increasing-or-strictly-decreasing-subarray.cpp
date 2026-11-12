class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans1=0;
        int i=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n&&nums[j]<nums[j-1])
            j++;
            ans1=max(ans1,j-i);
            i=j;
        }
        int ans2=0;
        i=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n&&nums[j]>nums[j-1])
            j++;
            ans2=max(ans2,j-i);
            i=j;
        }
        return max(ans1,ans2);
    }
};