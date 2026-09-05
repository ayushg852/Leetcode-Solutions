class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c=0;
        for(string &s:details)
        {
            if(stoi(s.substr(11,2))>60)
            c++;
        }
        return c;
    }
};