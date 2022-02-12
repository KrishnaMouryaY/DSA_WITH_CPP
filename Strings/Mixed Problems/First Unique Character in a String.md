### [First Unique Character in a String](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382157)
```
Problem Statement
Given a string ‘STR’ consisting of lower case English letters.
The task is to find the first non-repeating character in the string and return it. If it doesn’t exist, return ‘#’.

Sample Input 1:
2
bbabcbcb
babaabea
Sample Output 1:
a
e
Explanation Of Sample Input 1:
For the first test case, 
the first non-repeating character is ‘a’. 
As depicted the character ‘b’ repeats at index 1, 3, 5, 7, and character ‘c’ repeats at index 6. 
Hence we return the character ‘a’ present at index 2.

For the second test case, 
the character ‘e’ is the first non-repeating character. 
As depicted the character ‘b’ repeats at index 2, 5, and character ‘a’ repeats at index 3, 4, and 7. 
Hence we return the character ‘e’ present at index 6.

// Solution
char findNonRepeating(string str) {
    // Write your code here.
    int count[26] = {0};
    int ans = '#';
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[str[i] - 'a'] == 1) {
            return str[i];
        }
    }
    return ans;
}
```
