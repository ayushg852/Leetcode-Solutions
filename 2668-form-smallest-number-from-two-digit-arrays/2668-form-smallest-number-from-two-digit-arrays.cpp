class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int m1=10,m2=10,m=10;
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++)
        {
            m1=min(m1,nums1[i]);
            for(int j=0;j<n2;j++)
            {
                if(nums1[i]==nums2[j])
                m=min(m,nums1[i]);
                m2=min(m2,nums2[j]);
            }
        }
        if(m<10)
        return m;
        return min(m1,m2)*10+max(m1,m2);
    }
};