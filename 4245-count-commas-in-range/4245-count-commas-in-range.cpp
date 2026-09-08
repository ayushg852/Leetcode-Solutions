class Solution {
public:
    int countCommas(int n) {
        if(n<1e50)
        return max(0,n-999);
        return 99002;
    }
};