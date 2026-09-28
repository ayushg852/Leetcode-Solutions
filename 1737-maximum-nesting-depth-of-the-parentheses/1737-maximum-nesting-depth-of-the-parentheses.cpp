class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int c=0;
        for(auto &x:s)
        {
            if(x=='(')
            c++;
            else if(x==')')
            c--;
            ans=max(ans,c);
        }
        return ans;
    }
};