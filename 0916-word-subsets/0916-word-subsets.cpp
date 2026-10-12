class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> f(26);
        for(auto &s:words2)
        {
            vector<int> v(26);
            for(auto &c:s)
            v[c-'a']++;
            for(int i=0;i<26;i++)
            f[i]=max(f[i],v[i]);
        }
        vector<string> ans;
        for(auto &s:words1)
        {
            vector<int> v(26);
            for(auto &c:s)
            v[c-'a']++;
            int flag=1;
            for(int i=0;i<26;i++)
            {
                if(v[i]<f[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            ans.push_back(s);
        }
        return ans;
    }
};