class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s=0;
        int c=x;
        while(c>0)
        {
            s+=c%10;
            c/=10;
        }
        if(x%s==0)
        return s;
        return -1;
    }
};