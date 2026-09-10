class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a=max_element(nums.begin(),nums.end())-nums.begin();
        int b=min_element(nums.begin(),nums.end())-nums.begin();
        if(a>b)
        swap(a,b);
        int n=nums.size();
        int ans=0;
        if(a+1<=n-b)
        {
            ans+=a+1;
            ans+=min(b-a,n-b);
        }
        else
        {
            ans+=n-b;
            ans+=min(a+1,b-a);
        }
        return ans;
    }
};