class Solution {
public:
    int findPeakElement(vector<int>& ar) {
        int n=ar.size();
        if(n==1)
        return 0;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if((m==0&&ar[m+1]<ar[m])||(m==n-1&&ar[m-1]<ar[m])||(ar[m]>ar[m+1]&&ar[m]>ar[m-1]))
            return m;
            if(ar[m+1]>ar[m])
            l=m+1;
            else
            r=m-1;
        }
        return 1;
    }
};