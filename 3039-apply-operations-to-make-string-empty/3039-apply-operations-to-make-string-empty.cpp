class Solution {
public:
    string lastNonEmptyString(string s) {
        int n=s.size();
        vector<int> f(26);
        for(char &c:s)
        f[c-'a']++;
        vector<int> maxc(26);
        int maxf=*max_element(f.begin(),f.end());
        for(int i=0;i<26;i++)
        if(f[i]==maxf)
        maxc[i]=1;
        string ans="";
        for(int i=n-1;i>=0;i--)
        {
            if(maxc[s[i]-'a'])
            {
                ans+=s[i];
                maxc[s[i]-'a']=0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};