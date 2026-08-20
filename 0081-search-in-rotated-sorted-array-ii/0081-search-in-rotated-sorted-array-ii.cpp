class Solution {
public:
    bool search(vector<int>& ar, int t) {
        int l=0;
        int r=ar.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(ar[m]==t)
            return 1;
            if(ar[l]<ar[m])
            {
                if(t>=ar[l]&&t<ar[m])
                r=m-1;
                else
                l=m+1;
            }
            else if(ar[l]>ar[m])
            {
                if(t>ar[m]&&t<=ar[r])
                l=m+1;
                else
                r=m-1;
            }
            else
            {
                if(ar[r]==ar[m])
                {
                    l++;
                    r--;
                }
                else
                l=m+1;
            }
        }
        return 0;
    }
};