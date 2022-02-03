// Problem Statement
// You are given a sorted array 'A' of length 'N' with distinct integers and a target integer 'M'. You need to return the position of 'M' if it existed in the array 'A'. If it already exists in 'A', return that position. (0-based indexing)
// For example:
// If the given array 'A' is: [1, 2, 4, 7] and M = 6. We insert M = 6 in the array and get 'A' as: [1, 2, 4, 6, 7]. The position of 6 is 3 (according to 0-based indexing)
// Note:
// 1) The given array has distinct integers.

// 2) The given array may be empty.
// Input Format:
// The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. 

// Then the 'T' test cases follow.

// The first line of each test case contains two space-separated integers 'N' and 'M', representing the length of the array and the target integer.

// The second line of each test case contains 'N' space-separated integers, Ai representing the given array.
// Output Format:
// For each test case, print a single line containing a single integer denoting the position of 'M' in the final array, on a new line.

// The output of each test case will be printed in a separate line.
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints:
// 1 ≤ T ≤ 10
// 0 ≤ N ≤ 10 ^ 5
// 1 ≤ M ≤ 10 ^ 9
// 1 ≤ Ai ≤ 10 ^ 9

// Where 'T' is the number of test cases and 'Ai' is the array element at index 'i'.

// Time Limit: 1 sec.
// Follow Up:
// Try to solve the problem in O(log N).
// Sample Input 1:
// 2
// 4 6
// 1 2 4 7
// 4 9
// 1 2 4 7
// Sample Output 1:
// 3
// 4
// Explanation Of Input 1:
// The first test case is already explained in the problem statement.

// The second test case, the given array 'A' is: [1, 2, 4, 7] and M = 9. We insert M=9 in the array and get 'A' as: [1, 2, 4, 6, 9]. The position of 9 is 4 (according to 0-based indexing)

// without using stl functions
#include<bits/stdc++.h>
int countElements(vector<int> arr, int low, int high, int m, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            if (arr[mid] == x) {
                if (mid < m - 1 && arr[mid + 1] == x)
                    low = mid + 1;
                else
                    return mid;
            }
            else if (mid == m - 1 || arr[mid + 1] > x)
                return mid + 1;
            else
                low = mid + 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
    }
    return 0;
}


int bestInsertPos(vector<int> arr, int n, int m) {
    return countElements(arr, 0, n - 1, n, m); 
}

// using stl functions
#include<bits/stdc++.h>
int bestInsertPos(vector<int> arr, int n, int m) {
    if (binary_search(arr.begin(), arr.end(), m)) 
        return upper_bound(arr.begin(), arr.end(), m) - arr.begin() - 1;
    return upper_bound(arr.begin(), arr.end(), m) - arr.begin();  
}
