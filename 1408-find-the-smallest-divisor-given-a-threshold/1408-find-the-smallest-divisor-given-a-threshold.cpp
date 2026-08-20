class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        while(l<=r)
        {
            int m=(l+r)/2;
            int a=0;
            for(int i=0;i<n;i++)
            a+=ceil(1.0*nums[i]/m);
            if(a<=threshold)
            r=m-1;
            else
            l=m+1;
        }
        return l;
    }
};