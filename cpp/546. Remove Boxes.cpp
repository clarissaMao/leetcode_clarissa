class Solution {
public:
    // dp solution. dp[i][j][k] as the maximum points one can get by removing boxes of the subarray
    // boxes[i, j] (both inclusive) and there're k same elements left to boxes[i] which all equal to boxes[i].
    // dp[i][i][k] can be initialized. fo dp[i][j][k] which i!=j, there're two situations:
    // 1.consider i and previous k together and i+1 to j with k=0, we get (k + 1) * (k + 1) + dp[i+1][j][0].
    // 2.wait for another boxes[m] which also equals to boxes[i], then remove i, m and previous k together, we
    // get dp[i+1][m-1][0] + dp[m][j][k+1].
    // We take the maximum one as dp[i][j][k].
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[n][n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= i; k++) {
                dp[i][i][k] = (k + 1) * (k + 1);
            }
        }
        
        for (int l = 1; l < n; l++) {
            // l is the gap between i and j.
            for (int i = 0; i < n-l; i++) {
                int j = i + l;
                for (int k = 0; k <= i; k++) {
                    int res = (k + 1) * (k + 1) + dp[i+1][j][0];
                    for (int m = i+1; m <= j; m++) {
                        if (boxes[m]==boxes[i]) res = max(res, dp[i+1][m-1][0] + dp[m][j][k+1]);
                    }
                    dp[i][j][k] = res;
                }
            }
        }
        return dp[0][n-1][0];
    }
};