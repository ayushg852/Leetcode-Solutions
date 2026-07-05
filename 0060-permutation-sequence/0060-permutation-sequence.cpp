class Solution {
public:
set<char> s;
vector<int> fact;
string ans;
    void func(int k)
    {
        if(s.size()==1)
        {
            ans.push_back(*s.begin());
            return;
        }
        int d=fact[(s.size()-1)];
        int a=ceil( (double)k / d);
        auto it=s.begin();
        while(a-->1)
        it++;
        ans.push_back(*it);
        s.erase(it);

        k%=d;
        if(k>0)
        func(k);
        else if(s.size()>0)
        {
            it=prev(s.end());
            while(it!=s.begin())
            {
                ans.push_back(*it);
                it--;
            }
            ans.push_back(*it);
        }
    }
    string getPermutation(int n, int k) {
        fact.push_back(1);
        for(int i=1;i<=n;i++)
        {
            s.insert(i+'0');
            fact.push_back(fact.back()*i);
        }
        func(k);
        return ans;
    }
};