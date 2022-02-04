// Problem Statement
// You are given an array 'ARR' of 'N' integers and two integers 'K' and 'M'.
// You need to return true if the given array can be divided into pairs such that the sum of every pair gives remainder 'M' when divided by 'K'. Otherwise, you need to return false.
// For example:
// If the given array is [2, 1, 5, 7] and K = 9 and M = 3. Then you need to return true because we can divide the array into two pairs, i.e (2, 1) and (5, 7) whose sums are 3 and 12, which when divided by 9 gives remainder 3, thus it is possible to divide the given array into pairs.  
// Note:
// Every element of the array should contribute to only one pair, i.e if the array is [3, 0, 0] and K = 2 and M = 1, then you need to return false, as element 3 will make a pair with any one of the 0. 
// Input Format :
// The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. 
// Then the 'T' test cases follow.

// The first line of each test case contains an integer 'N' representing the size of the given array.

// The second line contains 'N' single space-separated integers representing the elements of the array 'ARR'.

// The third line contains two single space-separated integers 'K' and 'M'.
// Output Format :
// For each test case, print a single line containing either "True" or "False".
// Note:
// You do not need to print anything. It has already been taken care of. Just implement the given function.
// Constraint :
// 1 <= T <= 10
// 1 <= N <= 10 ^ 5
// 1 <= ARR[ i ] <= 10 ^ 9
// 1 <= K <= 10 ^ 9
// 0 <= M < K

// Where 'N' is the length of the array, 'ARR[ i ]' denotes the 'ith' element of array 'ARR' and 'K' and 'M' are the given integers.

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 4
// 2 1 5 7
// 9 3
// Sample Output 1:
// True
// Explanation For Input 1:
// Pairs will be {2,1} and {5,7} whose sums are 3 and 12 which will give remainder 3 when divided by 9.
// Sample Input 2:
// 1
// 5
// 6 6 3 0 0
// 9 3
// Sample Output 2:
// False
// Explanation For Input 2:
// As pairs would be {6, 6} and {3, 0}, but second 0 will not be able to make pair with any of the elements, thus it is not possible to make valid pairs.

// MY SOLUTION
#include <bits/stdc++.h>
bool isValidPair(vector<int> &arr, int n, int k, int m)
{
    // Write your code here.
   	vector<int> afterMod;
    for (int i = 0; i < n; i++) {
        afterMod.push_back(arr[i] % k);
    }
    int countPairs = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int sum = m;
        if (afterMod[i] > m)
            sum = m + k;
        if (mp.find(sum - afterMod[i]) != mp.end() && mp[sum - afterMod[i]] > 0) {
            countPairs++;
            mp[sum - afterMod[i]]--;
        }
        else
            mp[afterMod[i]]++;
    }
    if (countPairs*2 == n)
        return true;
    return false;
}
