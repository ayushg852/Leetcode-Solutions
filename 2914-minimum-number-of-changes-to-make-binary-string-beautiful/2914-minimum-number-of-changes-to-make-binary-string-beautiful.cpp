class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int ans=0;
        int i=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n&&s[j]==s[i])
            j++;
            if((j-i)&1)
            {
                ans++;
                i=j+1;
            }
            else
            i=j;            
        }
        return ans;
    }
};