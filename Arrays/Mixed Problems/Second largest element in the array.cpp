// Problem Statement
// You have been given an array/list 'ARR' of integers. Your task is to find the second largest element present in the 'ARR'.
// Note:
// a) Duplicate elements may be present.

// b) If no such element is present return -1.
// Example:
// Input: Given a sequence of five numbers 2, 4, 5, 6, 8.

// Output:  6

// Explanation:
// In the given sequence of numbers, number 8 is the largest element, followed by number 6 which is the second-largest element. Hence we return number 6 which is the second-largest element in the sequence.
// Input Format:
// The first line of input contains an integer ‘T’ denoting the number of test cases. 

// The next ‘2*T’ lines represent the ‘T’ test cases.

// The first line of each test case contains an integer ‘N’ denoting the number of elements in the array.

// The second line of each test case contains ‘N’ space-separated integers denoting the elements in the array. 
// Output Format:
// For each test case, print a single line containing a single integer denoting the second largest element in the array.

// The output of each test case will be printed in a separate line.
// Note:
// You are not required to print the expected output; it has already been taken care of, Just implement the function.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 5000
// -10 ^ 9 <= 'SIZE' <= 10 ^ 9 

// Where ‘T’ is the total number of test cases, ‘N’ denotes the number of elements in the array and ‘SIZE’ denotes the range of the elements in the array.

// Time limit: 1 sec.
// Sample Input 1:
// 2
// 6
// 12 1 35 10 34 1
// 5
// 10 10 10 10 10
// Sample Output 1:
// 34
// -1
// Explanation Of Sample Input 1:
// Test case 1: In the given sequence of numbers, number 35 is the largest element, followed by number 34 which is the second-largest element. Hence we return number 34 which is the second-largest element in the sequence.

// Test case 2: In the given sequence of numbers, number 10 is the largest element. However, since all the elements are the same, the second largest element does not exist. So, we return -1.


// My solution

int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int first = arr[0];
    int second = -1000000001;
    for (int i = 0; i < n; i++) {
		if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < first && arr[i] > second) {
        	second = arr[i];
        }   
    }
    if (second == -1000000001)
        return -1;
    return second;
}
