class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int m=n/2;
        int ls=0,rs=0;
        int lq=0,rq=0;
        for(int i=0;i<m;i++)
        {
            if(num[i]=='?')
            lq++;
            else
            ls+=num[i]-'0';
        }
        for(int i=m;i<n;i++)
        {
            if(num[i]=='?')
            rq++;
            else
            rs+=num[i]-'0';
        }
        if((lq+rq)%2)
        return true;
        int d=2*(ls-rs)+9*(lq-rq);
        return d!=0;
    }
};