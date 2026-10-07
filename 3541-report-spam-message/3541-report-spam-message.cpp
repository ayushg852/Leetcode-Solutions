class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s(bannedWords.begin(),bannedWords.end());
        int f=0;
        for(auto &x:message)
        {
            if(s.count(x))
            {
                if(f)
                return 1;
                f=1;
            }
        }
        return 0;
    }
};