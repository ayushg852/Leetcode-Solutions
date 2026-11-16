class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1,m2;
        for(auto &i:nums1)
        m1[i]++;
        for(auto &i:nums2)
        m2[i]++;
        int ans=0;
        for(auto &[i,j]:m1)
        {
            auto it=m2.find(i);
            int c=j;
            if(it!=m2.end())
            c+=(*it).second;
            if(c&1)
            {
                ans=-1;
                break;
            }
            ans+=max(0,2*j-c)/2;
            m2.erase(i);
        }
        for(auto &[i,j]:m2)
        {
            if(j&1)
            {
                ans=-1;
                break;
            }
        }
        return ans;
    }
};