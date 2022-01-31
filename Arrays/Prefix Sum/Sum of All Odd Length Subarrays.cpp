/*
Problem Statement:
Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.

 

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
*/


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // Approach Using Prefix sum array
        vector<int> prefixSum;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (i == 0)
                prefixSum.push_back(arr[i]);
            else
                prefixSum.push_back(prefixSum[i - 1] + arr[i]);
        }
        int sum = prefixSum[n - 1];
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j += 2) {
                if (i == 0) 
                    sum += prefixSum[j];
                else
                    sum += prefixSum[j] - prefixSum[i - 1]; 
            }
        }
        return sum;
        // without using prefix sum array
        // int sum = 0;
        // for (int i = 0; i < n; i++) {
        //     int count = 0;
        //     int curr_sum = 0;
        //     for (int j = i; j < n; j++) {
        //         count++;
        //         curr_sum += arr[j];
        //         if (count % 2 == 1)
        //             sum += curr_sum;
        //     }
        // }
        // return sum;
        
    }
};
