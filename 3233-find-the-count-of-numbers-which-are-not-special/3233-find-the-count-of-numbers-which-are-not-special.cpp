class Solution {
public:
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
    int nonSpecialCount(int l, int r) {
        int start=ceil(1.0*sqrt(l));
        int end=sqrt(r);
        int ans=0;
        for(int i=start;i<=end;i++)
        if(isPrime(i))
        ans++;
        return r-l+1-ans;
    }
};