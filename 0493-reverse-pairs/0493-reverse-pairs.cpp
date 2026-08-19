class Solution {
public:
    int ans=0;
    void merge_sort(vector<int> &arr,int l,int r)
    {
        if(l==r)
        return;
        int m=(l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        combine(arr,l,m,r);
    }
    void combine(vector<int> &arr,int l,int m,int r)
    {
        vector<int> v1(arr.begin()+l,arr.begin()+m+1);
        vector<int> v2(arr.begin()+m+1,arr.begin()+r+1);
        int a=v1.size();
        int b=v2.size();
        int i=0,j=0;
        for(i=0;i<a;i++)
        {
            while(j<b && v1[i]>2LL*v2[j])
            j++;
            ans+=j;
        }
        i=0;
        j=0;
        v1.push_back(INT_MAX);
        v2.push_back(INT_MAX);
        for(int k=l;k<=r;k++)
        {
            if(v1[i]<=v2[j])
            arr[k]=v1[i++];
            else
            arr[k]=v2[j++];
        }
    }
    int reversePairs(vector<int> nums) {
        merge_sort(nums,0,nums.size()-1);
        return ans;
    }
};