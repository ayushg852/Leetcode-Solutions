class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int ans=0;
        vector<int> freq(26);
        while(r<n)
        {
            freq[s[r]-'A']++;
            int max_freq=0;
            for(int i=0;i<26;i++)
            max_freq=max(max_freq,freq[i]);
            if(r-l+1-max_freq>k)
            freq[s[l++]-'A']--;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};