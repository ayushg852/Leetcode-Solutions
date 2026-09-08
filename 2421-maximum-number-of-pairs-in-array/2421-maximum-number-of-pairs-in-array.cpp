class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int a=0,b=0;;
        unordered_map<int,int> m;
        for(auto &x:nums)
        m[x]++;
        for(auto &[i,j]:m)
        {
            a+=j/2;
            b+=j%2;
        }
        return {a,b};
    }
};