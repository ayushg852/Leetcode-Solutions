class Solution {
public:
int func(int n,int k)
{
    int c=n/k;
    return k*c*(c+1)/2;
}
    int sumOfMultiples(int n) {
        return func(n,3)+func(n,5)+func(n,7)-func(n,15)-func(n,21)-func(n,35)+func(n,105);
    }
};