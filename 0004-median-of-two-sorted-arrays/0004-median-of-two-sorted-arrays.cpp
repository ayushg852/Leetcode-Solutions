class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        
        v1.push_back(INT_MAX);
        v2.push_back(INT_MAX);
        int n1=v1.size();
        int n2=v2.size();
        int j=0;
        int k=0;

        
        int n=n1+n2-2;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            if(v1[j]<=v2[k])
            arr[i]=v1[j++];
            else
            arr[i]=v2[k++];
        }

        double a;
        if(n%2!=0)
        a=arr[n/2];
        else
        a=(arr[n/2]+arr[n/2-1])/2.0000;

        return a;
    }
};