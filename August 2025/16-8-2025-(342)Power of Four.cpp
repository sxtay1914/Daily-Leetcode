class Solution {
//TC:O(1)
//SC:O(1)
public:
    bool isPowerOfFour(int n) {
        //4**x = n
        //x must be int 
        double exp = log(n)/log(4);
        return n>0 && fabs(exp - (int)exp)<1e-8;
    }
};