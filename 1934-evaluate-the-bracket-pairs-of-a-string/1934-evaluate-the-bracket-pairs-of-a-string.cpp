class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(auto &v:knowledge)
        m[v[0]]=v[1];
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!='(')
            ans+=s[i];
            else
            {
                int j=i+1;
                string t="";
                while(s[j]!=')')
                t+=s[j++];
                if(m.count(t))
                ans+=m[t];
                else
                ans+='?';
                i=j;
            }
        }
        return ans;
    }
};