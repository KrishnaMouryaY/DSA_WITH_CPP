// Problem Statement
// You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.
// Note :
// Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
// Input Format :
// The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case contains an Integer 'N' denoting the size of the array/list.

// The second line of each test case contains 'N' space-separated Integers denoting the array/list.
// Output Format :
// For each test case/query, print the sorted array/list(ARR) as space-separated Integers.

// Output for every test case will be printed in a separate line.
// Note:
// You need to change in the given array/list itself. Hence, no need to return or print anything.
// Constraints :
// 1 <= T <= 10
// 1 <= N <= (5 * (10 ^ 5))
// 0 <= ARR[i] <= 2

// Where 'N' is the size of the given array/list.
// And, ARR[i] denotes the i-th element in the array/list.

// Time Limit: 1sec 
// Sample Input 1 :
// 2
// 6
// 0 1 2 2 1 0
// 7
// 0 1 2 1 2 1 2
// Sample Output 1 :
// 0 0 1 1 2 2
// 0 1 1 1 2 2 2


//Approach 1
#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
   //   Write your code here
    int low = -1;
    int high = n;
    int i = 0;
    while (i < high) {
        if (arr[i] == 0) {
            low++;
            swap(arr[i], arr[low]);
            i++;
        }
        else if (arr[i] == 2) {
            high--;
            swap(arr[i], arr[high]);
        }
        else
            i++;
    }
}

//Approach 2
void sort012(int *arr, int n)
{
    int i = 0;
    int nextZero = 0;
    int nextTwo = n - 1;

    while (i <= nextTwo)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[nextZero]);
            i++;
            nextZero++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[nextTwo]);
            nextTwo--;
        }
        else
        {
            i++;
        }
    }
}
