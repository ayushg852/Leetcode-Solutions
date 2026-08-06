class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1e8;
        for(int i=0;i<n-2;i++)
        {
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int cur_sum=nums[i]+nums[l]+nums[r];
                if(cur_sum==target)
                return cur_sum;
                if(abs(target-cur_sum)<abs(target-ans))
                ans=cur_sum;

                if(cur_sum<target)
                l++;
                else
                r--;
            }
        }
        return ans;
    }
};