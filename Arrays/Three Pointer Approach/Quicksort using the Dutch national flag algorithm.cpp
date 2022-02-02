// Problem Statement
// You are given an array/list of integers. You are supposed to sort the array in non-decreasing order by applying Quicksort using the Dutch national flag algorithm.
// The Dutch National Flag algorithm is used to sort an array/list consisting of only three distinct elements in one iteration by placing all occurrences of the smallest element at the beginning of the array and all occurrences of the biggest element at the end of the array.
// Input Format:
// The first line contains a single integer ‘T’ denoting the number of test cases. 
// Then the test cases follow.

// The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array.

// The second line of each test case contains ‘N’ single space-separated integers denoting the elements of the array/list.
// Output Format:
// For each test case, print in a single line space-separated integers representing the elements of the given array/list in non-decreasing order.

// The output of each test case will be printed in a separate line.
// Note:
// You don’t need to print anything; It has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 5
// 1 <= N <= 10 ^ 5
// -10 ^ 9 <= ARR[i] <= 10 ^ 9

// Where 'ARR[i]' denotes the elements of the array.

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 5
// 4 2 1 4 2
// 5
// 5 2 7 3 5
// Sample Output 1:
// 1 2 2 4 4
// 2 3 5 5 7
// Explanation Of Sample Input 1:
// In the first test case, after arranging elements of the given array/list in non-decreasing order, we get {1,2,2,4,4}.

// In the second test case, after arranging elements of the given array/list in non-decreasing order, we get {2,3,5,5,7}.


#include <bits/stdc++.h>
void partioning(vector<int> &arr, int &low, int &high) {
    int p = arr[high];
    int mid = low;
    while (mid <= high) {
        if (arr[mid] < p) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] > p) {
            swap(arr[high], arr[mid]);
            high--;
        }
        else
            mid++;   
    }
}
void quickSort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int low = start;
        int high = end;
        partioning(arr, low, high);

        quickSort(arr, start, low - 1);
        quickSort(arr, high + 1, end);
    }
}

vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr)
{
    // Write your code here.
    quickSort(arr, 0, arr.size() - 1);
    return arr;
    	
}
