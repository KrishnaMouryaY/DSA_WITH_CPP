// Problem Statement
// You are given an integer of array/list 'ARR' of length ‘N. You are supposed to return true if it is possible to construct at least one non-degenerate triangle using values of array/list as sides of the triangle, otherwise, return false.
// Input Format:
// The first line contains a single integer ‘T’ denoting the number of test cases. The test cases follow.

// The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array.

// The second line contains ‘N’ single space-separated integers denoting the elements of the array/list.
// Output Format:
// For each test case, print a single line containing either “YES”(without quotes) if it is possible to form a non-degenerate triangle, otherwise “NO”(without quotes).

// The output of each test case will be printed in a separate line.
// Note:
// You don’t need to print anything; It has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 100
// 3 <= N <= 10 ^ 3
// 0 <= ARR[i] <= 10 ^ 9

// Where ‘T’ denotes the number of test cases, ‘N’ denotes the number of elements in the array, and 'ARR[i] denotes the elements of the array.

// Time Limit: 1 sec.
// Sample Input 1 :
// 2
// 5
// 4 2 1 3 2
// 5
// 5 2 7 3 15
// Sample Output 1:
// YES
// YES
// Explanation Of Sample Input 1:
// In the first test case, if we choose the sides as { 2,3,4} or {2,2,1} or {2,2,3} then it is possible to form a non-degenerate triangle.

// In the second test case, if we choose sides as {5,3,7}, then it is possible to form a non-degenerate triangle.

//My solution

#include <bits/stdc++.h>
bool checkTriangle(int a, int b, int c) {
    if (a + b > c && b + c > a && c + a > b)
        return true;
    return false;
}

bool possibleToMakeTriangle(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int a = 0;
    int b = 1;
    int c = 2;
    if (checkTriangle(arr[a], arr[b], arr[c]))
        return true;
    for (int i = 3; i < n; i++) {
        a++;
        b++;
        c++;
        if (checkTriangle(arr[a], arr[b], arr[c]))
            return true;
    }
    return false;
}

// Efficient approach
/* 
    Time Complexity: O(N * log(N))
    Space Complexity: O(log N)

    Where 'N' is the number of elements in the given array/list.
*/

#include <algorithm>

bool possibleToMakeTriangle(vector<int> &arr)
{

    // Sort the array in non-decreasing order.
    sort(arr.begin(), arr.end());

    int n = arr.size();

    // Iterate the array/list.
    for (int i = 0; i < n - 2; i++)
    {

        // Return true if sum of first 2 elements is greater than the 3rd element.
        if (arr[i] + arr[i + 1] > arr[i + 2])
        {
            return true;
        }
    }

    // If no non-degenerate triangle can be formed return false.
    return false;
}
