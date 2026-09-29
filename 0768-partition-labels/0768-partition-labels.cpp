class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> m(26);
        int n=s.size();
        for(int i=0;i<n;i++)
        m[s[i]-'a']=i;
        vector<int> ans;
        int j=0;
        int l=0;
        for(int i=0;i<n;i++)
        {
            if(i>j)
            {
                ans.push_back(j-l+1);
                l=i;
            }
            j=max(j,m[s[i]-'a']);
        }
        ans.push_back(n-l);
        return ans;
    }
};