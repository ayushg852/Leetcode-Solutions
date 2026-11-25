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
    bool completePrime(int num) {
        int m=1;
        int p=0;
        while(num>0)
        {
            if(!isPrime(num)||!isPrime(m*(num%10)+p))
            return false;
            p=m*(num%10)+p;
            m*=10;
            num/=10;
        }
        return 1;
    }
};