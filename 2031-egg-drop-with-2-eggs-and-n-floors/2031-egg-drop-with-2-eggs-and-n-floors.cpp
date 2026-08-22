class Solution {
public:
    int twoEggDrop(int n) {
        double det=sqrt(1.0+8*n);
        det-=1;
        return (int)(ceil(det/2.0)); 
    }
};