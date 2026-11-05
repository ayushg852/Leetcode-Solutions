class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            int p=9;
            for(int j=1;j<i;j++)
            p*=10-j;
            ans+=p;
        }
        return ans;
    }
};