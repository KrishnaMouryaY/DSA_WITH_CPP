### [Shortest Substring with all characters](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376559)
```
Problem Statement
You have been given a string 'S' which only consists of lowercase English-Alphabet letters. 
Your task is to find the shortest (minimum length) substring from 'S' which contains all the characters of 'S' at least once.
Sample Input 1:
2
aabcabb
abcdcda
Sample Output 1:
abc
abcd
Explanation For Sample Output 1:
Test Case 1 :

Some of the possible substrings are "aabcabb", "aabc", "abcab", "abc" 
having all the different characters of ‘S’ at least once. Out of all these substrings, 
we will have "abc", "bca" and "cab" with the shortest length. 

As "abc" appears earliest in the string, we will return "abc" in the output.

Test Case 2 :

Some of the possible substrings are “abcd”,
“bcdcda” having all the different characters of string ‘S’ at least once. “abcd” is the only substring with the shortest length. 

```
// Solution
string shortestSubstring(string s)
{
    // Write your code here.
    int n = s.length();
    int ct[26] = {0};
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (ct[s[i] - 'a'] == 0) {
            k++;
            ct[s[i] - 'a']++;
        }
    }
    int ansI = 0;
    int ansJ = n - 1;
    int start = 0;
    
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] == 1)
            k--;
        while (k == 0) {
            count[s[start] - 'a']--;
            if (count[s[start] - 'a'] == 0) {
                if (i - start < ansJ - ansI) {
                    ansI = start;
                    ansJ = i;
                } 
                k++;
            }
            start++;
        }
    }
	string ans;
    for (int i = ansI; i <= ansJ; i++)
        ans = ans + s[i];
    return ans;
}
```
