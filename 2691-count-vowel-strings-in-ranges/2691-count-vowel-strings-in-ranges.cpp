class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> p(n+1);
        string vowel="aeiou";
        for(int i=0;i<n;i++)
        {
            if(vowel.find(words[i][0])!=string::npos && vowel.find(words[i][words[i].size()-1])!=string::npos)
            p[i+1]=p[i]+1;
            else
            p[i+1]=p[i];
        }
        vector<int> ans;
        for(auto &v:queries)
        ans.push_back(p[v[1]+1]-p[v[0]]);
        return ans;
    }
};