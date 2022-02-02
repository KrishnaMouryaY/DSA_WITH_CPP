// Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.

// knapsack approach

int helper(int price[], int n, int N) {
        // 
        int dp[n + 1][N + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= N; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i - 1][j];
                    if (j - i >= 0)
                        dp[i][j] = max(dp[i][j], price[i - 1] + dp[i][j - i]);
                }
            }
        }
        return dp[n][N];
}
