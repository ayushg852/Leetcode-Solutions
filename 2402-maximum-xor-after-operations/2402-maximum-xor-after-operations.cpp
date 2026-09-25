class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int bit=0;bit<=26;bit++)
        {
            int f=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i] & (1<<bit))
                {
                    f=1;
                    break;
                }
            }
            if(f)
            ans+=1<<bit;
        }
        return ans;
    }
};