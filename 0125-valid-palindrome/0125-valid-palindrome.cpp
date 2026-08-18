class Solution {
public:
    bool isPalindrome(string s) {
        string n="";
        for(auto &c:s)
        {
            if(isalnum(c))
            n+=tolower(c);
        }
        string nn=n;
        reverse(n.begin(),n.end());
        if(nn==n)
        return 1;
        return 0;
    }
};