###[Longest Consecutive Sequence](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381889)

```
Problem Statement
You are given an unsorted array/list 'ARR' of 'N' integers. Your task is to return the length of the longest consecutive sequence.
The consecutive sequence is in the form ['NUM', 'NUM' + 1, 'NUM' + 2, ..., 'NUM' + L] where 'NUM' is the starting integer of the sequence and 'L' + 1 is the length of the sequence.
Note:
If there are any duplicates in the given array we will count only one of them in the consecutive sequence.
For Example-
For the given 'ARR' [9,5,4,9,10,10,6].

Output = 3
The longest consecutive sequence is [4,5,6].
Follow Up:
Can you solve this in O(N) time and O(N) space complexity?
Input Format :
The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. Then the 'T' test cases follow.

The first line of each test case contains integer 'N' denoting the size of the array.

The second line of each test case contains 'N' single space-separated integers, elements of the array.  
Output Format :
For each test case, print an integer in a single line that represents the length of the longest consecutive sequence.
Note :
You are not required to print the expected output; it has already been taken care of. Just implement the function. 
Constraints :
1 <= T <= 10
1 <= N <= 10^5
-10^9 <= ARR[i] <= 10^9

Time Limit: 1 sec
Sample Input 1 :
1 
5
33 20 34 30 35
Sample Output 1 :
3
Explanation To Sample Input 1 :
The longest consecutive sequence is [33, 34, 35].
Sample Input 2 :
1
7
1 9 3 10 4 20 2    
Sample Output 2 :
4
Explanation To Sample Input 2 :
The consecutive sequence is in the form ['NUM', 'NUM' + 1, 'NUM' + 2,...,'NUM' + 'L']. So in the given array, the longest consecutive sequence is [1,2,3,4] where 'NUM' = 1 and 'L' = 3. And the length of the sequence will be 'L' + 1 = 4.


// MY SOLUTION
// Sorting NlogN

#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    //unordered_set<int> :: iterator it;
    int ans = 0;
    for (auto it: s) {
        // no previous element
        if (s.find(it - 1) == s.end()) {
            int count = 1;
            while (s.find(it + 1) != s.end()) {
                it++;
                count++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

// Coding Ninjas Solution
/*  
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the length of the given array.
*/

#include <unordered_set>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // To store length of longest consecutive sequence.
    int mx = 0;

    // To store the length of current consecutive Sequence.
    int count = 0;

    // To store all the unique elements of array.
    unordered_set<int> set;

    for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int previousConsecutiveElement = arr[i] - 1;

        if (set.find(previousConsecutiveElement) == set.end()) {

            // 'arr[i]' is the first value of consecutive sequence.
            int j = arr[i];
            
            while (set.find(j) != set.end()) {
                // The next consecutive element by will be j + 1.
                j++;
            }

            // Update maximum length of consecutive sequence.
            mx = max(mx, j - arr[i]);
        }

    }

    return mx;
}
```
