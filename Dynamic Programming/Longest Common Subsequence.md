### [PROBLEM LINK HERE] (https://leetcode.com/problems/longest-common-subsequence/)
```
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.


#include<bits/stdc++.h>
int getLengthOfLCSHelper(int n1, string& s1, int n2, string& s2) {
//     if (n1 == 0 || n2 == 0)
//         return 0;
//     if (s1[n1 - 1] == s2[n2 - 1])
//         return 1 + getLengthOfLCSHelper(n1 - 1, s1, n2 - 1, s2);
//     else {
//         int u = getLengthOfLCSHelper(n1 - 1, s1, n2, s2);
//         int v = getLengthOfLCSHelper(n1, s1, n2 - 1, s2);
//         return max(u, v);
//     }
    int dp[n1 + 1][n2 + 1];
    for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n1][n2];
}


int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
    return getLengthOfLCSHelper(str1.size(), str1, str2.size(), str2);
    
}
```
