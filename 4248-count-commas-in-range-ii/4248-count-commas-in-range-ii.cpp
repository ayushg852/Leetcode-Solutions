class Solution {
public:
    long long powerOfTen(int x) {
    long long result=1;
    for(int i=0;i<x;i++)
        result*=10;
    return result;
}
    long long countCommas(long long n) {
        int d=0;
        long long copy=n;
        while(copy>0)
        {
            d++;
            copy/=10;
        }
        int a=(d-1)/3;
        long long ans=0;
        for(long long i=1;i<a;i++)
        {
            ans+=i*(powerOfTen(3*(i+1))-powerOfTen(3*i));
        }
        ans+=a*(n-powerOfTen(3*a)+1);
        return ans;
    }
};