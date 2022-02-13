### [Longest Sub-string With K Distinct Characters](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377986)
```
Problem Statement
You are given a string 'S' of length 'N' consisting of lowercase English alphabet letters. 
You are also given a positive integer 'K'.
Now, a substring of this string is good if it contains at most 'K' distinct characters. 
A string 'X' is a substring of string 'Y' if it can be obtained by deletion of several continuous elements(possibly zero) 
from the beginning and the end from the string 'Y'.
Your task is to return the maximum size of any good substring of the string 'S'.
Sample Input 1:
2
2
abcbc
1
abccc
Sample Output 1:
4
3
Explanation For Sample Input 1:
For the first test case :
K = 2, so we can choose substring “bcbc” having 2 distinct character which is less than or equal to K = 2. 

We cannot get any other substring of length 5 or more having distinct characters less than or equal to 2. 
Thus, you should return ‘4’ as the answer.

For the second test case :
K = 1, so we can choose substring “ccc” having only 1 distinct character which is less than or equal to K = 1. 

We cannot get any other substring of length 4 or more having distinct characters less than or equal to 1. 
Thus, you should return ‘3’ as the answer.

// BRUTE FORCE
int getLengthofLongestSubstring(string s, int k) {
    // Write your code here.
   int ans = 0;
   for (int i = 0; s[i] != '\0'; i++) {
       int count[256] = {0};
       int size = 0;
       int d = k;
       for (int j = i; s[j] != '\0'; j++) {
		int u = s[j];
           	if (count[s[j]] == 0) {
                   count[s[j]]++;
                   d--;
            	}
           	if (d < 0)
                   break;
            size++;
            ans = max(ans, size);
       }       
   }
   return ans;
}
// Optimised

int getLengthofLongestSubstring(string s, int k) {
  int n = s.size();
  if (k >= n || k == 26)
      return n;
  int size = 0;
  int ans = 0;
  int visited[256] = {0};
  int j = 0;
  for (int i = 0; i < n; i++) {
        size++;
        visited[s[i]]++;
        if (visited[s[i]] == 1) {
            k--;
        }
        while (k < 0) {
            visited[s[j]]--;
            if (visited[s[j]] == 0) {
                k++;
            }
            j++;
            size--;
        }
        ans = max(size, ans);    
    }    
    return ans;
}
```
