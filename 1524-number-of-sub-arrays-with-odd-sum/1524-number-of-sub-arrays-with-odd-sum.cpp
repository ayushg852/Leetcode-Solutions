class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int e=1;
        int o=0;
        int s=0;
        int ans=0;
        int m=1e9+7;
        for(int &i:arr)
        {
            s+=i;
            if(s&1)
            {
                ans=(ans+e)%m;
                o++;
            }
            else            
            {
                ans=(ans+o)%m;
                e++;
            }
        }
        return ans;
    }
};