class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &x:nums)
        {
            s.insert(x);
            int r=0;
            while(x>0)
            {
                r=r*10+x%10;
                x/=10;
            }
            s.insert(r);
        }
        return s.size();
    }
};