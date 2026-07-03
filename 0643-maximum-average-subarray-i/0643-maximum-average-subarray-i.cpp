class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int s=0;
        while(i<k)
        s+=nums[i++];
        int ans=s;
        while(i<nums.size())
        {
            s=s-nums[i-k]+nums[i];
            ans=max(ans,s);
            i++;
        }
        return (double)ans/k;
    }
};