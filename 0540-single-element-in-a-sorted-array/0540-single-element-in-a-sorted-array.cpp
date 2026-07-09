class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            int m=(l+r)/2;
            if(m==0||nums[m-1]!=nums[m])
            {
                if(m%2==0)
                l=m;
                else
                r=m-1;
            }
            else
            {
                if(m%2==1)
                l=m+1;
                else
                r=m-2;
            }
        }
        return nums[l];
    }
};