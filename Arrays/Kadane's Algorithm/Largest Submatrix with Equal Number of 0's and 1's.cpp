// Problem Statement
// You have been given a non-empty grid ‘MAT’ consisting of only 0s and 1s. Your task is to find the area of the largest sub-matrix having an equal number of 0s and 1s.
// If there is no such sub-matrix, print 0.
// For example, for the following grid:

// The largest sub-matrix having an equal number of 0s and 1s in the above grid is shown below :

// The area of the largest sub-matrix having an equal number of 0s and 1s is 4(rows in highlighted image) * 2(columns in highlighted image) = 8.
// Input Format:
// The first line of input contains an integer ‘T’ denoting the number of test cases. Then each test case follows.

// The first line of each test case contains two single space-separated integers ‘N’ and ‘M’ representing the number of rows and columns of the grid, respectively.

// The next 'N' lines of each test case contain 'M' single space-separated integers 0 or 1.
// Output Format:
// For each test case, print the area of the largest possible sub-matrix having an equal number of 0s and 1s. 

// Print the output of each test case in a separate line.
// Note
// You don’t have to print anything, it has already been taken care of. Just complete the function. 
// Constraints:
// 1 <= T <= 10^2
// 1 <= N <= 50
// 1 <= M <= 50
// MAT[i][j] = 0 or 1

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 2 2
// 1 0
// 0 0
// Sample Output 1:
// 2
// Explanation Of The Sample Input 1:
// The largest sub-matrix having an equal number of 0s and 1s in the above grid is shown below :

//brute force and approach 1 are same as submatrix with sum 0
// approach 2
#include <bits/stdc++.h>
int maximumLength(int* arr, int n) {
    unordered_map<long, int> mp;
        long sum = 0;
        mp[0] = -1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (mp.find(sum) != mp.end())
                    res = max(res, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return res;
}

int maximumArea(vector<vector<int>>& mat, int n, int m)
{
    // Write your code here.
    int res = 0;
    for (int startj = 0; startj < m; startj++) {
        int subMatrix[n] = {0};
        for (int j = startj; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int k = mat[i][j];
                if (k == 0)
                    k = -1;
                subMatrix[i] += k;
            }
            int u = j - startj + 1;
            int v = maximumLength(subMatrix, n);
            res = max(u * v, res);
        }
    }
    return res;
}

