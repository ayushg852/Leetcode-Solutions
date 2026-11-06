class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.size();
        vector<int> v(n);
        int p=0;
        int c=0;
        for(int i=1;i<n;i++)
        {
            if(s[i-1]=='1')
            c++;
            p+=c;
            v[i]+=p;
        }
        p=0;
        c=0;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i+1]=='1')
            c++;
            p+=c;
            v[i]+=p;
        }
        return v;
    }
};