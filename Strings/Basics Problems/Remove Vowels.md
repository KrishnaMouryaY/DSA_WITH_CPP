### [Remove Vowels](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377977)

```
Problem Statement
You are given a string STR of length N. Your task is to remove all the vowels present in that string and print the modified string.
English alphabets ‘a’, ‘e’, ‘i’, ‘o’, ‘u’ are termed as vowels. All other alphabets are called consonants.
Note: You have to only remove vowels from the string. There will be no change in the relative position of all other alphabets.
For Example:
(i)  If the input string is 'CodeGeek', the output should be CdGk after removing ‘o’ and ‘e’.

(ii) If the input string is 'Odinson', the output should be 'dnsn' after removing ‘o’ and ‘i’. 
Input Format:
The first line of input contains an integer 'T' representing the number of the test case. Then the test case follows.

The first and only line of each test case contains a string STR of length N.
Output Format:
For each test case, return the modified string that contains ‘NO VOWELS’.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^4

STR may contain alphabets from 'a' to 'z' or 'A' to 'Z' and blank spaces.

Time Limit: 1 sec 
Sample Input 1:
2
Mobile
CodingNinjas
Sample Output 1:
Mbl
CdngNnjs
Explanation Of Input 1:
(i) The output ‘Mbl’ is obtained after removing vowels ‘o’ and ‘i’ from second and fourth position respectively of given string ‘Mobile’.

(ii) The output ‘CdngNnjs’ is obtained after removing vowels ‘o’, ‘i’, ‘i’, and ‘a’ from second, fourth, eighth, and eleventh position respectively of given string ‘CodingNinjas’.

// Solution
bool checkVowels(char i) {
    if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
        return true;
    if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
        return true;
    return false;
}
string removeVowels(string inputString) {
    // Write your code here.
    string ans = "";
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (checkVowels(inputString[i]))
            continue;
        ans.push_back(inputString[i]);
    }
    return ans;
}
```
