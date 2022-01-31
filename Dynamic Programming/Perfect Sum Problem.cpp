// Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Example 1:

// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
//        sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10}
// consider case with 0's in array

int mod = 1000000007;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        // if (n == 0) {
        //     if (sum == 0)
        //         return 1;
        //     else
        //         return 0;
        // }
    
        // int exclude = perfectSum(arr, n - 1, sum);
        // int include = 0;
        // if (sum >= arr[n - 1])
        //     include = perfectSum(arr, n - 1, sum - arr[n - 1]);
        // return exclude + include;
        long long dp[n + 1][sum + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0) {
                    if (j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else {
                dp[i][j] = dp[i - 1][j] % mod;
                if (j >= arr[i - 1])
                    dp[i][j] += (dp[i - 1][j - arr[i - 1]]) % mod;
                }
            }
        }
        return dp[n][sum] % mod;
	}
	  
