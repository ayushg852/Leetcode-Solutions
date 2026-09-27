class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int b=0;
        for(int x:nums)
        if (x==k)
        b++;
        int ans=b;
        for(int v=1;v<=50;v++)
        {
            if(v==k)
            continue;
            int cur=0;
            int best=0;
            for(int x:nums)
            {
                if(x==v)
                cur++;
                else if(x==k)
                cur--;
                cur=max(cur,0);
                best=max(best,cur);
            }
            ans=max(ans,b+best);
        }
        return ans;
    }
};