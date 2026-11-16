class Solution {
public:
    string digitSum(string s, int k) {
        string t="";
        while(s.size()>k)
        {
            int n=s.size();
            for(int i=0;i<n;i+=k)
            {
                int a=0;
                for(int j=i;j<n&&j<i+k;j++)
                a+=s[j]-'0';
                t+=to_string(a);
            }
            s=t;
            t="";
        }
        return s;
    }
};