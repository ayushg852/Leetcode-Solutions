class Solution {
public:
    int findMin(vector<int>& ar) {
        int mi=50001;
        int l=0;
        int r=ar.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(ar[l]<=ar[m])
            {
                mi=min(mi,ar[l]);
                l=m+1;
            }
            else
            {
                mi=min(mi,ar[m]);
                r=m-1;
            }
        }
        return mi;
    }
};