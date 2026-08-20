class Solution {
public:
    int search(vector<int>& ar, int k) {
        int l=0;
        int r=ar.size()-1;
        int m;
        while(l<=r)
        {
            m=(l+r)/2;
            if(ar[m]==k)
            return m;
            else if(ar[m]>k)
            r=m-1;
            else
            l=m+1;
        }
        return -1;
    }
};