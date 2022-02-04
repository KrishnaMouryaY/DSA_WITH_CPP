// Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


// Example 1:

// Input: V = 30, M = 3, coins[] = {25, 10, 5}
// Output: 2
// Explanation: Use one 25 cent coin
// and one 5 cent coin
// Example 2:
// Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
// Output: 2 
// Explanation: Use one 6 cent coin
// and one 5 cent coin

// Your Task:  
// You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

// Expected Time Complexity: O(V*M)
// Expected Auxiliary Space: O(V)

// Approach 1 Recursion 1;
int mC2(vector<int> &coins, int sum, int n) {
    if (sum == 0)   
	return 0;   
    if (n == 0)   
	return -1;
    int n1 = -1;
    int n2 = -1;
    n1 = mC2(coins, sum, n - 1);
    if (coins[n - 1] <= sum)   
	n2 = mC2(coins, sum - coins[n - 1], n);
    if (n2 != -1)   n2 += 1;
    if (n1 == -1 && n2 == -1)   
	return -1;
    if (n1 == -1 || n2 == -1)   
	return n1 + n2 + 1;
    return min(n1, n2);
}

// Recursion 2
int mC(vector<int> &coins, int sum, int n) {
    if (sum == 0)   
	return 0;
    int count = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int val = -1;
        if (sum - coins[i] >= 0)    val = mC(coins, sum - coins[i], n);
        if (val != -1)  count = min(count, val);
    }
    if (count == INT_MAX) return -1;
    else    return ++count;
}

// DP - 1
int mC2dp(vector<int> &coins, int sum, int n) {
    //vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    int dp[n + 1][sum + 1];
    for (int i = 0;  i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if(j == 0) dp[i][j] = 0;
            else if (i == 0) dp[i][j] = -1;
            else
            {
                int n1 = -1;
                int n2 = -1;
                n1 = dp[i - 1][j];
                if (coins[i - 1] <= j)   
                    n2 = dp[i][j - coins[i - 1]];
                if (n2 != -1)  
                    n2 += 1;
                if (n1 == -1 && n2 == -1)   
                    dp[i][j] = -1;
                else if (n1 == -1 || n2 == -1)   
                    dp[i][j] = n1 + n2 + 1;
                else   
                    dp[i][j] = min(n1, n2);
            }
        }
    }
    return dp[n][sum];
}

// DP - 2
int mCdp(vector<int> &coins, int sum, int n) {
    vector<int> dp(sum + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        int check = INT_MAX;
        for (int j = 0; j < n; j++)
        {  
            int val = -1;
            if (i - coins[j] >= 0)   val = dp[i - coins[j]];
            if (val != -1)   check = min(check, val);
        }
        if (check == INT_MAX)   dp[i] = -1;
        else   dp[i] = 1 + check;
    }
    return dp[sum];
}
// Aditya Verma Dp- solution
int minCoins(int coins[], int n, int sum) 
    { 
        int dp[n+1][sum+1];
      
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
            
        for(int i=0;i<=sum;i++)
            dp[0][i] = INT_MAX-1;
    
        for(int i=1;i<=n;i++)
            for(int j=1;j<=sum;j++)
            {
                if(coins[i-1]<=j)        //note the indices values here
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        if(dp[n][sum]==INT_MAX-1)   //add this condition
            return -1;
        return dp[n][sum];
    } 
