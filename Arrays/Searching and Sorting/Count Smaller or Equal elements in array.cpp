// Problem Statement
// You are given two arrays of integers. Let's call the first array A and the second array B. A finds the number of elements in array B that are smaller than or equal to that element for every array element.
// For Example:
// A = [2, 3, 0] , B = [5, 1]

// For the first index, A[0] = 2
// In array B only 1 is less than 2. Therefore the answer for the first index is 1.

// For the second index, A[1] = 3
// In array B only 1 is less than 3. Therefore the answer for the second index is also 1.

// For the third index, A[2] = 0
// Both the elements of array B are greater than 0. 
// Therefore the answer for the third index is 0.

// Hence, the final answer is [1,1,0] in this case.
// Input Format:
// The first line of input contains an integer ‘T’ denoting the number of test cases.
// Then the test case follows.

// The first line of each test case contains an integer ‘N’ denoting the number of elements in the array A. 

// The second line of each test case contains ‘N’ space-separated integers denoting the elements of array A.

// The third line of each test case contains an integer ‘M’ denoting the number of elements in array B. 

// The second line of each test case contains ‘M' space-separated integers denoting the elements of array B.
// Output Format:
// For each test case, print N space-separated integers represent the number of elements in array B that are smaller than the corresponding element in array A.
// Note:
// You are not required to print the expected output, it has already been taken care of. Just implement the function.
// Constraints:
// 1 <= T <= 10
// 1 <= N,M <= 10^4
// -10^9 <= A[i] , B[i] <= 10^9

// Time limit: 1 second
// Sample Input 1:
// 1
// 5
// 5 4 3 2 1
// 2
// 3 4
// Sample Output 1:
// 2 2 1 0 0
// Explanation Of Sample Input 1 :
// For the first index, A[0] = 5
// Both the elements of Array B are less than 5. Therefore the answer for the first index is 2.

// For the second index, A[1] = 4
// In array B, one element is smaller than 4 and one element is equal to 4. Therefore the answer for the second index is also 2.

// For the third index, A[2] = 3
// In array B only one element is equal to 3. Therefore the answer for the third index is 1.

// For the fourth index, A[3] = 2
// Both the elements of Array B are greater than 2. Therefore the answer for the fourth index is 0.

// For the fifth index, A[4] = 1
// Both the elements of Array B are greater than 1. Therefore the answer for the last index is 0.

// Hence, the final answer is [2, 2, 1, 0, 0] in this case


#include <bits/stdc++.h>
int countElements(int *arr, int low, int high, int m, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            if (mid == m - 1 || arr[mid + 1] > x)
                return mid + 1;
            else if (arr[mid] == x) {
                if (arr[mid + 1] == x)
                    low = mid + 1;
                else
                    return mid + 1;
            }
            else
                low = mid + 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
    }
    return 0;
}

vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) {
    //  Write your code here  
    sort(b, b + m);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int k = countElements(b, 0, m - 1, m, a[i]);
        v.push_back(k);
    }
    return v;
}

// Using upper_bound()
/*
  Time Complexity: O((N + M) * log(M))
  Space complexity: O(1)
  
  where N and M are lengths of array A and B respectively
*/

#include<algorithm>

vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) {
    
    //  Initiliazing answer vector arr
    vector < int > arr;
    
    // Sorting the array B
    sort(b, b + m);

    // Traversing the array A
    for (int i = 0; i < n; i++) {
    
        // Handling the case when all elements of array B are smaller
        if (a[i] >= b[m - 1]) {
            arr.push_back(m);
        }

        // Finding the leftmost index having greater value than current element
        // We will convert the iterator returned by upper bound to find the corresponding index 
        // We will append that index to answer vector
        else {
            int idx = upper_bound(b, b + m, a[i]) - b;
            arr.push_back(idx);
        }
    }
    return arr;
}
