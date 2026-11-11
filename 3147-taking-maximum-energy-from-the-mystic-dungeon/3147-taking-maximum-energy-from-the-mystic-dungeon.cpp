class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans=INT_MIN;
        int n=energy.size();
        for(int i=n-1;i>n-1-k;i--)
        {
            int s=0;
            for(int j=i;j>=0;j-=k)
            {
                s+=energy[j];
                ans=max(ans,s);
            }
        }
        return ans;
    }
};