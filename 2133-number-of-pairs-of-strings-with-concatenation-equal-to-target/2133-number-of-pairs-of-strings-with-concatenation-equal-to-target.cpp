class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int> m;
        for(auto &s:nums)
        m[s]++;
        string p="";
        int ans=0;
        int n=target.size();
        for(int i=0;i<n-1;i++)
        {
            p+=target[i];
            string s=target.substr(i+1,n-1-i);
            if(p==s)
            {
                if(m.count(p))
                ans+=m[p]*(m[p]-1);
            }
            else if(m.count(p)&&m.count(s))
            ans+=m[p]*m[s];
        }
        return ans;
    }
};