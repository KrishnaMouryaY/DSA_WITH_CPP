/*
Problem Statement
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items available in the store and the weight and value of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.
Note: The thief is not allowed to break the items.
For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.

Sample Input:
1 
4 5
1 2 4 5
5 4 8 6
Sample Output:
13
Explanation Of Sample Output 1
The most optimal way to fill the knapsack is to choose items with weight 4 and value 8, weight 1 and value 5.

The total value of the knapsack =  8 + 5 = 13.

*/

#include <bits/stdc++.h>
// int dp[1000][1000];
// int helper(vector<int> &values, vector<int> &weights, int n, int w)
// {
//     if (n == 0 || w == 0)
//         return dp[n][w] = 0;
//     if (dp[n][w] != -1)
//         return dp[n][w];
//     int u = helper(values, weights, n - 1, w);
//     if (w >= weights[n - 1])
//         u = max(u, values[n - 1] + helper(values, weights, n - 1, w - weights[n - 1]));
//     return dp[n][w] = u;
// }
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
//     memset(dp, -1, sizeof(dp));
//     return helper(values, weights, n, w);
	// Write your code here
    /*if (n == 0 || w == 0)
        return 0;
    int u = maxProfit(values, weights, n - 1, w);
    if (w >= weights[n - 1])
        u = max(u, values[n - 1] + maxProfit(values, weights, n - 1, w - weights[n - 1]));
    return u;*/
    
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
            	dp[i][j] = 0;
            else {
                if (j >= weights[i - 1])
                    dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
   }
  return dp[n][w];
}
