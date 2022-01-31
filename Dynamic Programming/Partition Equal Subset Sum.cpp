/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

*/

// Approach 1
class Solution {
public:
    bool helper(vector<int>& nums, int n, int diff) {
        // recursive problem
       
        bool dp[n + 1][diff + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= diff; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j - 2*nums[i - 1] >= 0)
                        dp[i][j] = dp[i][j] || dp[i - 1][j - 2*nums[i - 1]];
                }
            }
        }
        return dp[n][diff];
    }
    
    bool canPartition(vector<int>& nums) {
        int diff = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            diff += nums[i];
        }
        if (diff % 2 == 1)
            return false;
        return helper(nums, nums.size(), diff);
    }
};

//Approach 2
// if there exists two subsets with equal sum then total sum = s1 + s2; and s1 = s2; totalsum = 2s1; s1 = totalsum/2;
//so we should find if there exists a subset with sum totalsum/2
