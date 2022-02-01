// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1
 

//Approach 1
class Solution {
public:
    int helper(vector<int>& nums, int n, int diff, int target) {
//         if (n == 0) {
//             if (diff == target)
//                 return 1;
//             return 0;     
//         }
        
//         int res = helper(nums, n - 1, diff, target);
//         if (diff - 2 * nums[n - 1] >= target)
//             res += helper(nums, n - 1, diff - 2 * nums[n - 1], target);
        
//         return res;
        int dp[n + 1][diff + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= diff; j++) {
                if (i == 0) {
                    if (j == target)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    if (j - 2* nums[i - 1] >= target)
                        dp[i][j] += dp[i - 1][j - 2 * nums[i - 1]];  
                }
            }
        }
        return dp[n][diff];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (target < 0)
            target = -1 * target;
        return helper(nums, n, sum, target);
    }
};
