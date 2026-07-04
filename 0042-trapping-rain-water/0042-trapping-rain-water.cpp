class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3)
        return 0; 
        vector<int> p(n);
        p[0]=height[0];
        for(int i=1;i<n-1;i++)
        {
            p[i]=max(p[i-1],height[i]);
        }
        vector<int> s(n);
        s[n-1]=height[n-1];
        for(int i=n-2;i>0;i--)
        {
            s[i]=max(s[i+1],height[i]);
        }        
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+=max(0,min(p[i],s[i])-height[i]);
        }
        return ans;
    }
};