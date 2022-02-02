// Problem Statement
// Given a 2-dimensional matrix of size ‘N’ x ‘M’. Find the size of the largest sub-matrix whose sum is equal to 0. The size of a matrix is the product of rows and columns in it.
// A sub-matrix is a matrix obtained from the given matrix by deletion of several (possibly, zero or all) rows/columns from the beginning and several (possibly, zero or all) rows/columns from the end.
// For example :

// If there is no sub-matrix with sum equal to 0, then return 0.
// Input Format
// The first line of input contains an integer 'T' representing the number of test cases. Then the test cases follow.

// The first line of each test case contains two single-spaced integers 'N' and 'M', representing the number of rows and columns of the matrix, respectively.

// The next 'N' lines contain 'M' single-spaced integers denoting matrix elements. 
// Output Format:
// For each test case, in the first line, print an integer denoting the size of the largest sub-matrix with sum equal to 0.

// The output of each test case is printed in a separate line.
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 10
// 1 <= N, M <= 50
// -10^5 <= data <= 10^5,

// Where ‘data’ is the value of the elements of the matrix.

// Time Limit: 1 sec
// Sample Input 1:
// 3
// 3 3
// 1 2 3
// 2 -3 -2
// 3 4 5
// 2 3
// 1 2 -4
// 0 5 4
// 1 2
// 5 3
// Sample Output 1:
// 4
// 2
// 0
// Explanation Of Sample Input 1:
// In the 1st test case, there is only one sub-matrix of size 4(2 x 2) with sum equal to 0.

// In the 2nd test case, there are two sub-matrix of size 2(2 x 1) and 1(1 x 1) with sum equal to 0.

// In the 3rd test case, there is no sub-matrix with sum equal to 0.

// brute force same as maximum rectangle sum
// approach 1 same as maximum rectangle sum
// approach 2
#include <bits/stdc++.h>
int largestArrayWithSumZero(int* arr, int n) {
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

int largestSubmatrixWithSumZero(vector<vector<int>> &mat, int n, int m)
{
	// Write your code here.
    int res = 0;
    for (int startj = 0; startj < m; startj++) {
        int subMatrix[n] = {0};
        for (int j = startj; j < m; j++) {
            for (int i = 0; i < n; i++)
                subMatrix[i] += mat[i][j];
            int u = j - startj + 1;
            int v = largestArrayWithSumZero(subMatrix, n);
            res = max(u * v, res);
        }
    }
    return res;
}
