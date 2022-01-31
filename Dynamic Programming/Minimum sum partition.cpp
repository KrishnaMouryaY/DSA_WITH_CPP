// // Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

// Example 1:

// Input: N = 4, arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11   

// Example 2:

// Input: N = 2, arr[] = {1, 4}
// Output: 3
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {4}, sum of Subset2 = 4

    int helper(int arr[], int n, int diff) {
        // if (diff == 0)
        //     return 0;
        // if (n == 0)     
        //     return diff;
        // int exclude = helper(arr, n - 1, diff);
        // int include = INT_MAX;
        // if (diff - 2*arr[n - 1] >= 0)
        //     include = helper(arr, n - 1, diff - 2*arr[n - 1]);
        // return min(include, exclude);
        int dp[n + 1][diff + 1];
        for (int i = 0; i <= n; i++) {
            for(int j = 0; j <= diff; j++) {
                if (j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = j;
                else {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= 2*arr[i - 1])
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 2*arr[i - 1]]);
                }
            }
        }
        return dp[n][diff];
   
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int diff = 0;
	    for (int i = 0; i < n; i++)
	        diff += arr[i];
	   return helper(arr, n, diff);
	} 
