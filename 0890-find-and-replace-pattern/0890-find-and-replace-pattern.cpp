class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<pair<char,char>> v(26,{' ',' '});
        vector<string> ans;
        int n=pattern.size();
        for(auto &s:words)
        {
            int f=1;
            for(int i=0;i<n;i++)
            {
                if(v[s[i]-'a'].first!=' '&&v[s[i]-'a'].first!=pattern[i])
                f=0;
                else if(v[pattern[i]-'a'].second!=' '&&v[pattern[i]-'a'].second!=s[i])
                f=0;
                else
                {
                    v[s[i]-'a'].first=pattern[i];
                    v[pattern[i]-'a'].second=s[i];
                }
            }
            if(f)
            ans.push_back(s);
            fill(v.begin(),v.end(),make_pair(' ',' '));
        }
        return ans;
    }
};