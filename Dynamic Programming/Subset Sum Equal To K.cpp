
// Problem Statement
// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
// Sample Input 1:
// 2
// 4 5
// 4 3 2 1
// 5 4
// 2 5 1 6 7
// Sample Output 1:
// true
// false
// Explanation For Sample Input 1:
// In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum = 5. These are {4,1} and {3,2}. Hence, return true.
// In example 2, ‘ARR’ is {2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return false.


class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        /// here 
        // if (sum == 0)
        //     return true;
        // if (N == 0)
        //     return false;
            
        // bool include = isSubsetSum(N - 1, arr, sum - arr[N - 1]);
        // bool exclude = isSubsetSum(N - 1, arr, sum);
        // return include || exclude;
        bool dp[N + 1][sum + 1];
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else
                {
                    bool exclude = dp[i - 1][j];
                    bool include = false;
                    if (arr[i - 1] <= j)
                        include = dp[i - 1][j - arr[i - 1]];
                    dp[i][j] = include || exclude;
                }
            }
        }
        return dp[N][sum];
        
    }
};
