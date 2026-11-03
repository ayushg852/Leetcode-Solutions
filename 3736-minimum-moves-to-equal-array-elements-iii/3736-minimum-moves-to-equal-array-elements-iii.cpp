class Solution {
public:
    int minMoves(vector<int>& nums) {
        int s=0;
        int m=1;
        for(int i=0;i<nums.size();i++)
        {
            m=max(m,nums[i]);
            s+=nums[i];
        }
        return nums.size()*m-s;
    }
};