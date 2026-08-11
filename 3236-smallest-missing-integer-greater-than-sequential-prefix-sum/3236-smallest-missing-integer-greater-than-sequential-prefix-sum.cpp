class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0];
        unordered_set<int> st;
        st.insert(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]!=1)
            {
                while(i<n)
                st.insert(nums[i++]);
                break;
            }
            s+=nums[i];
        }
        while(st.count(s))
        s++;
        return s;
    }
};