class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    int n;
    bool isPalin(string &t)
    {
        for(int i=0;i<t.size()/2;i++)
        if(t[i]!=t[t.size()-i-1])
        return false;
        return true;
    }
    void func(int i,string &s)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++)
        {
            string part=s.substr(i,j-i+1);
            if(isPalin(part))
            {
                temp.push_back(part);
                func(j+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();  
        func(0,s);
        return ans;
    }
};