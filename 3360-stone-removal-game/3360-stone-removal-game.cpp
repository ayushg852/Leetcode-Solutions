class Solution {
public:
    bool canAliceWin(int n) {
        int demand=10;
        while(n>=demand)
        {
            n-=demand;
            demand--;
        }
        if(demand&1)
        return 1;
        return 0;
    }
};