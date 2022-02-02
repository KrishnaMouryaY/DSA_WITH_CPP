// Problem Statement
// You are given a matrix ‘ARR’ with ‘N’ rows and ‘M’ columns. Your task is to find the maximum sum rectangle in the matrix.
// Maximum sum rectangle is a rectangle with the maximum value for the sum of integers present within its boundary, considering all the rectangles that can be formed from the elements of that matrix.
// For Example
// Consider following matrix:

// The rectangle (1,1) to (3,3) is the rectangle with the maximum sum, i.e. 29.

// Input Format
// The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test cases follow.

// The first line of each test case contains two space-separated integers ‘N’ and ‘M’ denoting the number of rows and number of columns respectively.

// The next ‘N’ lines contain ‘M’ space-separated integers denoting the elements of ARR.
// Output Format
// For each test case, print the value of the sum for the maximum sum rectangle.

// Print the output of each test case in a separated line.
// Note
// You do not need to print anything; it has already been taken care of. Just implement the given function.
// Constraints
//  1 <= T <= 10
//  1 <= M, N <= 75
//  -10^5 <= ARR[i][j] <= 10^5

// Time Limit: 1 sec
// Sample Input 1
// 2
// 1 2
// -1 1
// 2 2
// -1 1
// 2 2
// Sample Output 1
// 1
// 4
// Explanation Of Input 1
// The maximum sum rectangle corresponding to the first test case is-

// The maximum sum rectangle corresponding to the second test case is-


// brute force approach
int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
	// write your code here
    int res = arr[0][0];
    for (int starti = 0; starti < n; starti++) {
        for (int startj = 0; startj < m; startj++) {
            for (int endi = starti; endi < n; endi++) {
                for (int endj = startj; endj < m; endj++) {
                    int subMatrixSum = 0;
                    
                    for (int i = starti; i <= endi; i++) 
                        for (int j = startj; j <= endj; j++) 
                            subMatrixSum += arr[i][j];

                    res = max(res, subMatrixSum);
                }
            }
        }
    }
    return res;
}
// Efficient Approach
int kadanesSubSum (int* arr, int n) {
    int res = arr[0];
    int subSum = arr[0];
    for (int i = 1; i < n; i++) {
        subSum = max(subSum + arr[i], arr[i]);
        res = max(subSum, res);
    }
    return res;
}
int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
	// write your code here
    int res = arr[0][0];
    
    for (int startj = 0; startj < m; startj++) {
        int subMatrix[n] = {0};
        for (int j = startj; j < m; j++) {
            for (int i = 0; i < n; i++)
                subMatrix[i] += arr[i][j];
            res = max(res, kadanesSubSum(subMatrix, n));
        }
    }
    return res;
}


// Efficient approach 2
int kadanesSubSum (int* arr, int n) {
        int res = arr[0];
        int subSum = arr[0];
        for (int i = 1; i < n; i++) {
            subSum = max(subSum + arr[i], arr[i]);
            res = max(subSum, res);
        }
        return res;
}
int maximumSumRectangle(int n, int m, vector<vector<int>> arr) {
// code here
	int res = arr[0][0];

	for (int starti = 0; starti < n; starti++) {
	    int subMatrix[m] = {0};
	    for (int i = starti; i < n; i++) {
		for (int j = 0; j < m; j++)
		    subMatrix[j] += arr[i][j];
		res = max(res, kadanesSubSum(subMatrix, m));
	    }
	}
	return res;
}
