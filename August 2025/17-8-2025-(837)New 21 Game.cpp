class Solution {
//O(N)
//O(N)
public:
    double new21Game(int n, int k, int maxPts) {
        if (k<=0) return 1.0;
        vector<double> dp(n+1);
        double wsum = (k>0)? 1: 0, res = 0;
        dp[0] = 1;
        //sliding window is from 1 to maxPts
        
        for (int i=1; i<=n; i++){
            dp[i] = wsum/maxPts;
            if (i<k){
                wsum += dp[i];
            }else{
                res += dp[i];
            }

            if (i-maxPts>=0 && i-maxPts<k){
                wsum -= dp[i-maxPts];
            }
        }
        return res;
    }
};
