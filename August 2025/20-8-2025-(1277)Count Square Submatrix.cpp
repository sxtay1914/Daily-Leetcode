class Solution {
//tc: O(R*C)
//sc: O(R*C)
public:
    int countSquares(vector<vector<int>>& matrix) {
        //dp problem, one thing i didnt realise is that square needs diagonal, upper and lower to be same
        int ans = 0, row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col));
        for (int r=0; r<row; r++){
            for (int c=0; c<col; c++){
                if (r==0 || c==0){
                    if (matrix[r][c]==1)dp[r][c] = 1;
                    ans+=dp[r][c];
                    continue;
                }
                if(matrix[r][c]==1)dp[r][c] = min({dp[r-1][c-1], dp[r-1][c], dp[r][c-1]}) + 1;
                ans+=dp[r][c];
            }
        }
        // for (int r = 0; r<row; r++){
        //     for (int c = 0; c<col; c++){
        //         ans += dp[r][c];
        //     }
        // }
        return ans; 
    }
};