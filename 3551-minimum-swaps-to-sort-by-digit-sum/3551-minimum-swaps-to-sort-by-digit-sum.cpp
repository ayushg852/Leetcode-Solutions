class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        v[i]={nums[i],i};
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
            int sa=0;
            int aa=a.first;
            while(aa>0)
            {
                sa+=aa%10;
                aa/=10;
            }
            int sb=0;
            int bb=b.first;
            while(bb>0)
            {
                sb+=bb%10;
                bb/=10;
            }
            if(sa==sb)
            return a.first<b.first;
            return sa<sb;
        });
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i].second!=-1)
            {
                int cur=i;
                int c=0;
                while(v[cur].second!=-1)
                {
                    int t=cur;
                    cur=v[t].second;
                    v[t].second=-1;
                    c++;
                }
                ans+=c-1;
            }
        }
        return ans;
    }
};