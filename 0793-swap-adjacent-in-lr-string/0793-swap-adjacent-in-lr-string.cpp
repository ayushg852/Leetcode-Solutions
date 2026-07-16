class Solution {
public:
    bool canTransform(string s, string t) {
        int n = s.size();

        // Remove X and compare order
        string a="", b="";
        for(char c:s) if(c!='X') a+=c;
        for(char c:t) if(c!='X') b+=c;

        if(a!=b) return false;

        // Compare positions
        int i=0, j=0;

        while(i<n && j<n)
        {
            while(i<n && s[i]=='X') i++;
            while(j<n && t[j]=='X') j++;

            if(i==n || j==n) break;

            if(s[i]=='L' && i<j) return false;
            if(s[i]=='R' && i>j) return false;

            i++; j++;
        }

        return true;
    }
};
