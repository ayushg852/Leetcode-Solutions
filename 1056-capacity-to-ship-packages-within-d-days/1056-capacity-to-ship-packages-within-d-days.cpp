class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1;
        int r=1e9;
        while(l<=r)
        {
            int m=(l+r)/2;
            int d=1;
            int cur=0;
            for(auto &x:weights)
            {
                if(x>m)
                {
                    d=days+1;
                    break;
                }
                if(cur+x>m)
                {
                    d++;
                    cur=x;
                }
                else
                cur+=x;
            }
            if(d<=days)
            r=m-1;
            else
            l=m+1;
        }
        return l;
    }
};