### [Encode the Message](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377976)
```
Problem Statement
You have been given a text message. You have to return the Run-length Encoding of the given message.
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as the character and a single count. For example, the string "aaaabbbccdaa" would be encoded as "a4b3c2d1a2".
Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow:

The first and only line of each test case will contain a string denoting the message.
Note:
It's guaranteed that the message string will have no digits and consists solely of lowercase alphabetic characters.
Output Format:
For each test case, print a single line containing the encoded message string. 

Output for every test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
1 <= N <= 100000

Where 'N' is the length of the message string.

Time Limit: 1 sec
Sample Input 1 :
3
aabbc
abcd
abbdcaas
Sample Output 1 :
a2b2c1
a1b1c1d1
a1b2d1c1a2s1
Explaination For Sample Input 1:
Test Case 1: As 2 consecutive 'a', 2 consecutive 'b', and 1 'c' are present in the given string so output is "a2b2c1".

Test Case 2: As 1 consecutive 'a', 1 consecutive 'b', 1 consecutive 'c' and 1 consecutive 'd' are present in the given string so output is "a1b1c1d1".

Test Case 3: As 1 consecutive 'a', 2 consecutive 'b', 1 consecutive 'd', 1consecutive 'c', 2 consecutive 'a' and 1 consecutive 's' are present in the given string so output is "a1b2d1c1a2s1".
Sample Input 2:
2
sadasd
adsad
Sample Output 2:
s1a1d1a1s1d1
a1d1s1a1d1

// Solution
#include<bits/stdc++.h>
string encode(string &message)
{
    //   Write your code here.
    string ans = "";
    int i = 0;
    int j;
    while (message[i] != '\0') {
        ans.push_back(message[i]);
        j = i + 1;
        while (message[j] != '\0' && message[j] == message[i]) {
            j++;
        }
        ans.append(to_string(j - i));
        i = j;
    }
    return ans;
}
```
