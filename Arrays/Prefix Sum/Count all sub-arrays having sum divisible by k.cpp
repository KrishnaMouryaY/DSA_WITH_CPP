/*
Problem statement:

Given an array ‘ARR’ and an integer ‘K’, your task is to find all the count of all sub-arrays whose sum is divisible by the given integer ‘K’.

2
3 2
2 3 1
4 1
1 2 3 4
Sample Output 1:
3
10
Explanation Of Sample Input 1:
Test Case 1:

Given ‘ARR’ is { 2, 3,1 } and ‘K’ is ‘2’.
All the sub-array with sum is divided by ‘K’ are -
{ 2 }  because the sum is 2 and sum 2 is divisible by 2
{ 3, 1 } because the sum is 3 + 1 = 4 and sum 4 is divisible by 2.
{ 2, 3, 1 } because the sum is 2 + 3 + 1 = 6 and sum 6 is divisible by 2.

Hence there is a total of three subarrays that has sum divisible by 2.


Test Case 2:

Given ‘ARR’ is { 1, 2, 3, 4 } and ‘K’ is ‘1’.
Given ‘K’ is 1 that’s why each and every sub-arrays sum will be divisible by ‘1’ and with the size of ‘4’ array total number of subarray possible is ‘( 4*5 /2 ) = 20/2 = 10’.
All possible subarray -
{ 1 }, { 2 }, { 3 }, { 4 }, { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 2, 3 }, { 2, 3, 4 }, { 1, 2, 3, 4 } and all subarray sum is divisible by ‘1’.
Hence there are overall 10 subarrays that has sum divisible by ‘1’.
*/

// Approach using hashmap

int subArrayCount(vector<int> &arr, int k) {
    // Write your code here.
    int n = arr.size();
   	unordered_map<int, int> m;
    int count = 0;
    long long sum = 0;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
        int rem = (sum % k);
        if (rem < 0)
            rem += k;
        if (m.find(rem) != m.end()) {
            count += m[rem];
            m[rem]++;
        }
        else
            m[rem] = 1;
    }
    return count;
}





