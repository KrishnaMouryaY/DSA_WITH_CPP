// Problem Statement
// You are given an array 'ARR' consisting of 'N' integers and a non-negative integer 'K'. Consider an operation on the array as replacing every element 'ELE' of the array with 'MX - ELE', where 'MX' is the maximum element of the array. You need to return the updated array, given that this operation is performed on the array exactly 'K' number of times.
// Note:
// 1. The array follows 0-based indexing.
// 2. Note that after each operation, the next operation will be performed on the updated array i.e the array obtained after the last operation.
// Input Format:
// The first line of the input contains an integer 'T' denoting the number of test cases.

// The first line of each test case contains two integers 'N' and 'K', denoting the size of the array and the number of times operation is to be performed respectively.

// The second line of each test case contains N space-separated integers denoting the array elements.
// Output Format:
// For each test case, print single space-separated integers denoting the array elements after 'K' operations.
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 10^4
// -10^9 <= ARR[i] <= 10^9
// 0 <= K <= 10^9

// Time Limit: 1sec
// Sample Input 1:
// 1
// 4 2
// 20 15 10 5
// Sample Output 1:
// 15 10 5 0
// Explanation For Sample Input 1:
// The given array’s 0-based indexing is as follows:

// In the first operation, maximum = 20.

// 20    15    10    5     
// ↓      ↓    ↓     ↓
// 0      5    10    15

// These will be the array values, after one operation.

// In the second operation,  maximum = 15.

// 0      5     10    15     
// ↓      ↓      ↓     ↓
// 15     10     5     0

// Now the array to be returned is {15, 10, 5, 0}.
// Sample Input 2:
// 1
// 4 3
// 0 0 9 18
// Sample Output 2:
// 18 18 9 0  

#include <bits/stdc++.h>
void helper(vector<int> &ans, int N) {
   	int M = ans[0];
    for (int i = 0; i < N; i++) {
        if (ans[i] > M)
            M = ans[i];
    }
    for (int i = 0; i < N; i++) 
        ans[i] = M - ans[i];
}
vector<int> printArrayAfterKOperations(vector<int> &arr, int N, int K) {

	// Write your code here.
    if (K == 0)
        return arr;
    
    bool checkZeroes = false;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0)
            checkZeroes = true;
        	break;
    }
    if (checkZeroes == false) {
        helper(arr, N);
        K--;
    }
    
    K = K % 2;
    
    if (K == 0)
        return arr;
    else {
        helper(arr, N);
        return arr;
    }
}
