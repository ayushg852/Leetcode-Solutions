class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        int i=0;
        int j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int c=0;
        while(j<s.size()&&i<g.size())
        {
            if(s[j]>=g[i])
            {
                c++;
                i++;
            }
            j++;
        }
        return c;
    }
};